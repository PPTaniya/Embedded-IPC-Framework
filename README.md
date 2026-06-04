# 🚀 Embedded IPC Framework

![C++](https://img.shields.io/badge/C%2B%2B-20-blue)
![Linux](https://img.shields.io/badge/Linux-POSIX-green)
![Build](https://img.shields.io/badge/Build-CMake-orange)
![IPC](https://img.shields.io/badge/IPC-Framework-red)
![Status](https://img.shields.io/badge/Status-In%20Development-yellow)

A modular and extensible **C++ IPC Framework** for Linux-based Embedded Systems and Automotive ECUs.

The framework abstracts multiple IPC mechanisms behind a common API and demonstrates:

* 🚀 Modern C++20
* 🐧 Linux System Programming
* 🔄 Inter-Process Communication (IPC)
* 🧵 Multithreading
* 📡 Event-Driven Architecture
* 🔒 Synchronization
* 📦 Serialization
* 🏗️ Framework Design

---

# 🎯 Objectives

Build a reusable IPC framework supporting:

✅ UNIX Domain Sockets

✅ Shared Memory

✅ POSIX Message Queues

✅ Publish / Subscribe

✅ Producer / Consumer

✅ epoll Event Loop

✅ Thread Pool

✅ Serialization

---

# 🏛️ High Level Architecture

```text
┌───────────────────────────────────────────────────────┐
│                   Applications                        │
├───────────────────────────────────────────────────────┤
│ sensor_service.cpp                                   │
│ dashboard_client.cpp                                 │
│ logger_service.cpp                                   │
│ ecu_gateway.cpp                                      │
└───────────────────────────────────────────────────────┘
                        │
                        ▼
┌───────────────────────────────────────────────────────┐
│                  IPC Framework                        │
└───────────────────────────────────────────────────────┘
                        │
                        ▼

┌───────────────────────────────────────────────────────┐
│ API Layer                                             │
├───────────────────────────────────────────────────────┤
│ ipc_client.hpp / ipc_client.cpp                       │
│ ipc_server.hpp / ipc_server.cpp                       │
│ publisher.hpp / publisher.cpp                         │
│ subscriber.hpp / subscriber.cpp                       │
└───────────────────────────────────────────────────────┘
                        │
                        ▼
┌───────────────────────────────────────────────────────┐
│ Transport Layer                                       │
├───────────────────────────────────────────────────────┤
│ itransport.hpp                                        │
│ uds_transport.hpp / uds_transport.cpp                 │
│ shm_transport.hpp / shm_transport.cpp                 │
│ mq_transport.hpp / mq_transport.cpp                   │
└───────────────────────────────────────────────────────┘
                        │
                        ▼
┌───────────────────────────────────────────────────────┐
│ Core Infrastructure                                   │
├───────────────────────────────────────────────────────┤
│ event_loop.hpp / event_loop.cpp                       │
│ thread_pool.hpp / thread_pool.cpp                     │
│ ring_buffer.hpp / ring_buffer.cpp                     │
└───────────────────────────────────────────────────────┘
                        │
                        ▼
┌───────────────────────────────────────────────────────┐
│ Common Utilities                                      │
├───────────────────────────────────────────────────────┤
│ message.hpp                                           │
│ serializer.hpp                                        │
│ logger.hpp / logger.cpp                               │
│ types.hpp                                             │
└───────────────────────────────────────────────────────┘
                        │
                        ▼
┌───────────────────────────────────────────────────────┐
│ Linux Kernel APIs                                     │
├───────────────────────────────────────────────────────┤
│ socket()                                              │
│ epoll_wait()                                          │
│ shm_open()                                            │
│ mmap()                                                │
│ mq_send()                                             │
│ mq_receive()                                          │
└───────────────────────────────────────────────────────┘
```

---

# 📂 Project Structure

```text
embedded-ipc-framework/
│
├── CMakeLists.txt
├── README.md
│
├── include/
│   └── ipc/
│       ├── common/
│       │   ├── message.hpp
│       │   ├── serializer.hpp
│       │   ├── logger.hpp
│       │   └── types.hpp
│       │
│       ├── core/
│       │   ├── event_loop.hpp
│       │   ├── thread_pool.hpp
│       │   └── ring_buffer.hpp
│       │
│       ├── transport/
│       │   ├── itransport.hpp
│       │   ├── uds_transport.hpp
│       │   ├── shm_transport.hpp
│       │   └── mq_transport.hpp
│       │
│       └── api/
│           ├── ipc_client.hpp
│           ├── ipc_server.hpp
│           ├── publisher.hpp
│           └── subscriber.hpp
│
├── src/
│   └── ipc/
│       ├── common/
│       │   └── logger.cpp
│       │
│       ├── core/
│       │   ├── event_loop.cpp
│       │   ├── thread_pool.cpp
│       │   └── ring_buffer.cpp
│       │
│       ├── transport/
│       │   ├── uds_transport.cpp
│       │   ├── shm_transport.cpp
│       │   └── mq_transport.cpp
│       │
│       └── api/
│           ├── ipc_client.cpp
│           ├── ipc_server.cpp
│           ├── publisher.cpp
│           └── subscriber.cpp
│
├── apps/
│   ├── models/
│   ├── sensor_service.cpp
│   ├── dashboard_client.cpp
│   ├── logger_service.cpp
│   └── ecu_gateway.cpp
│
├── tests/
│   ├── test_serializer.cpp
│   ├── test_ringbuffer.cpp
│   └── test_ipc.cpp
│
└── scripts/
    ├── run_demo.sh
    └── cleanup.sh
```

---

# 🔄 Message Flow

```text
sensor_service
      │
      ▼
IPCServer
      │
      ▼
UDS Transport
      │
      ▼
IPC Framework
      │
      ▼
IPCClient
      │
      ▼
dashboard_client
```

---

# 🛠️ Build

```bash
git clone <repository-url>

cd embedded-ipc-framework

mkdir build
cd build

cmake ..
make -j$(nproc)
```

---

# ▶️ Run Demo

### Terminal 1

```bash
./sensor_service
```

### Terminal 2

```bash
./dashboard_client
```

Expected Output:

```text
Sensor ID: 1
Temperature: 35.2
Pressure: 1.1
```

---

# 📋 Development Roadmap

## Phase 1

* [x] Project Structure
* [x] Message Abstraction
* [x] Serialization
* [x] Transport Interface
* [x] UNIX Domain Socket Transport
* [x] IPC Client
* [x] IPC Server

## Phase 2

* [ ] epoll Event Loop
* [ ] Multi-Client Support
* [ ] Logger Service

## Phase 3

* [ ] Shared Memory Transport
* [ ] Ring Buffer
* [ ] Producer / Consumer Synchronization

## Phase 4

* [ ] POSIX Message Queue Transport
* [ ] Publish / Subscribe Messaging

## Phase 5

* [ ] Thread Pool
* [ ] Unit Testing
* [ ] Benchmarking

---

# 🧪 Testing

```text
tests/
├── test_serializer.cpp
├── test_ringbuffer.cpp
└── test_ipc.cpp
```

---

# 💡 Linux Concepts Demonstrated

* 🐧 Linux System Programming
* 🔌 UNIX Domain Sockets
* 🧠 Shared Memory
* 📨 POSIX Message Queues
* ⚡ epoll
* 🔒 Synchronization
* 🧵 Multithreading
* 📦 Serialization
* 🔄 Producer / Consumer
* 🎯 Event-Driven Design
* 🏗️ Framework Design
* ♻️ RAII
* 🎨 Polymorphism

---

# 🔮 Future Enhancements

* Lock-Free Ring Buffer
* Asynchronous Logger
* Heartbeat Monitoring
* Auto-Reconnect
* Topic-Based Routing
* Configuration Support
* Performance Benchmark Suite
* GoogleTest Integration

---

# 👨‍💻 Author

**Papechen P**

Embedded Software Engineer | Linux | Automotive ECU Development | C++

---

# 📄 License

MIT License
