# Embedded IPC Framework

A modular and extensible C++ framework for Inter-Process Communication (IPC) in Linux-based embedded systems and ECU applications.

The framework abstracts multiple IPC mechanisms behind a common API and demonstrates modern C++ design, Linux system programming, synchronization, serialization, and event-driven architectures.

---

# Features

## Supported

* UNIX Domain Sockets (UDS)
* Client / Server Communication
* Serialization Framework
* Modular Transport Abstraction
* CMake Build System

## Planned

* Shared Memory Transport
* POSIX Message Queues
* Publish / Subscribe Messaging
* epoll Event Loop
* Thread Pool
* Ring Buffer
* Producer / Consumer Synchronization
* Logging Framework
* Unit Tests

---

# Architecture

```text
+--------------------------------------------------+
|                  Applications                    |
+--------------------------------------------------+
| Sensor Service                                   |
| Dashboard Client                                 |
| Logger Service                                   |
| ECU Gateway                                      |
+--------------------------------------------------+

                Uses IPC Framework

+--------------------------------------------------+
|                 IPC Framework                    |
+--------------------------------------------------+
| API Layer                                        |
|--------------------------------------------------|
| IPCClient                                        |
| IPCServer                                        |
| Publisher                                        |
| Subscriber                                       |
+--------------------------------------------------+
| Transport Layer                                  |
|--------------------------------------------------|
| Unix Domain Socket Transport                     |
| Shared Memory Transport                          |
| POSIX Message Queue Transport                    |
+--------------------------------------------------+
| Core Infrastructure                              |
|--------------------------------------------------|
| Event Loop (epoll)                               |
| Thread Pool                                      |
| Ring Buffer                                      |
| Logger                                           |
| Serializer                                       |
+--------------------------------------------------+

+--------------------------------------------------+
|                 Linux Kernel                     |
+--------------------------------------------------+
| epoll | socket | shm_open | mmap | mq_*          |
+--------------------------------------------------+
```

---

# Project Structure

```text
embedded-ipc-framework/
│
├── CMakeLists.txt
├── README.md
│
├── include/
│   └── ipc/
│       ├── common/
│       ├── core/
│       ├── transport/
│       └── api/
│
├── src/
│   └── ipc/
│       ├── common/
│       ├── core/
│       ├── transport/
│       └── api/
│
├── apps/
│   ├── models/
│   ├── sensor_service.cpp
│   ├── dashboard_client.cpp
│   ├── logger_service.cpp
│   └── ecu_gateway.cpp
│
├── tests/
│
└── scripts/
```

---

# Framework Components

## Common

Reusable data structures and utilities.

* Message
* MessageHeader
* Serializer
* Logger
* Common Types

## Core

Framework infrastructure.

* Event Loop
* Thread Pool
* Ring Buffer

## Transport

IPC transport implementations.

### UNIX Domain Socket Transport

* Local IPC communication
* Stream-based communication
* Client / Server architecture

### Shared Memory Transport

* High throughput communication
* Zero-copy data exchange
* Ring buffer support

### POSIX Message Queue Transport

* Command messaging
* Event notification
* Priority support

## API

User-facing interfaces.

* IPCClient
* IPCServer
* Publisher
* Subscriber

---

# Message Flow

```text
Sensor Service
      |
      |
      V
IPC Framework
      |
      |
      V
Dashboard Client
```

---

# Build Requirements

## Compiler

* GCC 11+
* Clang 14+

## Dependencies

* Linux
* CMake 3.16+
* POSIX Threads

---

# Build

```bash
mkdir build
cd build

cmake ..
make -j$(nproc)
```

---

# Run

## Terminal 1

```bash
./sensor_service
```

## Terminal 2

```bash
./dashboard_client
```

Example Output:

```text
Sensor ID : 1
Temperature : 35.2
Pressure : 1.1
```

---

# Design Principles

## Separation of Concerns

The IPC framework is completely independent of application-specific payloads.

Application-specific structures such as:

```cpp
struct SensorData
{
    uint32_t sensorId;
    float temperature;
    float pressure;
};
```

remain outside the framework.

The framework only transports generic messages.

---

## Transport Abstraction

All IPC mechanisms implement a common interface.

```cpp
class ITransport
{
public:
    virtual bool send(const Message&) = 0;
    virtual bool receive(Message&) = 0;
    virtual int getFd() const = 0;

    virtual ~ITransport() = default;
};
```

This allows transports to be swapped without changing application code.

---

## Extensibility

New transports can be added by implementing the transport interface.

Examples:

* TCP Transport
* CAN Transport
* SOME/IP Transport
* DDS Transport

---

# Current Development Status

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
* [ ] Unit Tests
* [ ] Performance Benchmarking

---

# Testing

Unit tests are located under:

```text
tests/
├── test_serializer.cpp
├── test_ringbuffer.cpp
└── test_ipc.cpp
```

---

# Demo Applications

## Sensor Service

Produces simulated sensor data.

## Dashboard Client

Consumes and displays sensor data.

## Logger Service

Receives and stores messages.

## ECU Gateway

Acts as a routing and dispatching component between services.

---

# Linux Concepts Demonstrated

* UNIX Domain Sockets
* POSIX Shared Memory
* POSIX Message Queues
* epoll
* Producer / Consumer Pattern
* Synchronization
* Serialization
* Event-Driven Design
* Multithreading
* Modern C++
* RAII
* Polymorphism
* Design Patterns

---

# Future Enhancements

* Lock-Free Ring Buffer
* Asynchronous Logging
* Heartbeat Monitoring
* Automatic Reconnection
* Topic-Based Routing
* Configuration Files
* Benchmark Suite
* GoogleTest Integration

---

# License

MIT License
