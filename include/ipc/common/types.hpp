#pragma once

#include <cstdint>
#include <vector>

namespace ipc
{

using Byte = uint8_t;

using ByteBuffer = std::vector<Byte>;

enum class MessageType : uint32_t
{
    UNKNOWN      = 0,
    SENSOR_DATA  = 1,
    COMMAND      = 2,
    HEARTBEAT    = 3,
    LOG_MESSAGE  = 4
};

}
