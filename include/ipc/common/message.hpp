#pragma once

#include <cstdint>
#include <vector>

namespace ipc
{

enum class MessageType : uint32_t
{
    SENSOR_DATA = 1,
    LOG_DATA,
    HEARTBEAT,
    COMMAND
};

struct MessageHeader
{
    uint32_t type;
    uint32_t size;
    uint64_t timestamp;
};

struct Message
{
    MessageHeader header;
    std::vector<uint8_t> payload;
};

}
