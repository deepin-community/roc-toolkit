/*
 * Copyright (c) 2020 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <CppUTest/TestHarness.h>

#include "roc_address/socket_addr.h"
#include "roc_core/buffer_factory.h"
#include "roc_core/cond.h"
#include "roc_core/heap_arena.h"
#include "roc_core/mutex.h"
#include "roc_netio/network_loop.h"
#include "roc_packet/concurrent_queue.h"
#include "roc_packet/packet_factory.h"

namespace roc {
namespace netio {

namespace {

enum { MaxBufSize = 500 };

core::HeapArena arena;
core::BufferFactory<uint8_t> buffer_factory(arena, MaxBufSize);
packet::PacketFactory packet_factory(arena);

UdpReceiverConfig make_receiver_config(const char* ip, int port) {
    UdpReceiverConfig config;
    CHECK(config.bind_address.set_host_port(address::Family_IPv4, ip, port));
    return config;
}

class RecordingCompleter : public INetworkTaskCompleter {
public:
    RecordingCompleter()
        : cond_(mutex_)
        , task_(NULL) {
    }

    virtual void network_task_completed(NetworkTask& task) {
        core::Mutex::Lock lock(mutex_);
        task_ = &task;
        cond_.broadcast();
    }

    NetworkTask* wait_task() {
        core::Mutex::Lock lock(mutex_);
        while (!task_) {
            cond_.wait();
        }
        return task_;
    }

private:
    core::Mutex mutex_;
    core::Cond cond_;
    NetworkTask* task_;
};

class AddRemoveCompleter : public INetworkTaskCompleter {
public:
    AddRemoveCompleter(NetworkLoop& net_loop)
        : net_loop_(net_loop)
        , cond_(mutex_)
        , add_task_(NULL)
        , remove_task_(NULL) {
    }

    ~AddRemoveCompleter() {
        delete add_task_;
        delete remove_task_;
    }

    void start(UdpReceiverConfig& config, packet::IWriter& writer) {
        core::Mutex::Lock lock(mutex_);

        add_task_ = new NetworkLoop::Tasks::AddUdpReceiverPort(config, writer);
        net_loop_.schedule(*add_task_, *this);
    }

    void wait() {
        core::Mutex::Lock lock(mutex_);

        while (!remove_task_ || !remove_task_->success()) {
            cond_.wait();
        }
    }

    virtual void network_task_completed(NetworkTask& task) {
        core::Mutex::Lock lock(mutex_);

        if (&task == add_task_) {
            roc_panic_if_not(net_loop_.num_ports() == 1);

            roc_panic_if_not(add_task_->success());
            roc_panic_if_not(add_task_->get_handle());

            remove_task_ = new NetworkLoop::Tasks::RemovePort(add_task_->get_handle());
            net_loop_.schedule(*remove_task_, *this);

            return;
        }

        if (&task == remove_task_) {
            roc_panic_if_not(net_loop_.num_ports() == 0);

            roc_panic_if_not(remove_task_->success());
            cond_.signal();

            return;
        }

        roc_panic("unexpected task");
    }

private:
    NetworkLoop& net_loop_;

    core::Mutex mutex_;
    core::Cond cond_;

    NetworkLoop::Tasks::AddUdpReceiverPort* add_task_;
    NetworkLoop::Tasks::RemovePort* remove_task_;
};

} // namespace

TEST_GROUP(tasks) {};

TEST(tasks, synchronous_add) {
    NetworkLoop net_loop(packet_factory, buffer_factory, arena);
    CHECK(net_loop.is_valid());

    UdpReceiverConfig config = make_receiver_config("127.0.0.1", 0);
    packet::ConcurrentQueue queue(packet::ConcurrentQueue::Blocking);

    NetworkLoop::Tasks::AddUdpReceiverPort task(config, queue);

    CHECK(!task.success());
    CHECK(!task.get_handle());

    CHECK(net_loop.schedule_and_wait(task));

    CHECK(task.success());
    CHECK(task.get_handle());
}

TEST(tasks, asynchronous_add) {
    NetworkLoop net_loop(packet_factory, buffer_factory, arena);
    CHECK(net_loop.is_valid());

    UdpReceiverConfig config = make_receiver_config("127.0.0.1", 0);
    packet::ConcurrentQueue queue(packet::ConcurrentQueue::Blocking);

    NetworkLoop::Tasks::AddUdpReceiverPort task(config, queue);

    CHECK(!task.success());
    CHECK(!task.get_handle());

    RecordingCompleter completer;

    net_loop.schedule(task, completer);

    CHECK(completer.wait_task() == &task);

    CHECK(task.success());
    CHECK(task.get_handle());
}

TEST(tasks, asynchronous_add_remove) {
    NetworkLoop net_loop(packet_factory, buffer_factory, arena);
    CHECK(net_loop.is_valid());

    UdpReceiverConfig config = make_receiver_config("127.0.0.1", 0);
    packet::ConcurrentQueue queue(packet::ConcurrentQueue::Blocking);

    AddRemoveCompleter completer(net_loop);

    UNSIGNED_LONGS_EQUAL(0, net_loop.num_ports());

    completer.start(config, queue);
    completer.wait();

    UNSIGNED_LONGS_EQUAL(0, net_loop.num_ports());
}

} // namespace netio
} // namespace roc
