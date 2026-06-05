#pragma once

#include "ipc/common/types.hpp"

#include <cstdint>

namespace ipc
{

struct MessageHeader
{
    uint32_t type;
    uint32_t size;
    uint64_t timestamp;
};

struct Message
{
    MessageHeader header;
    ByteBuffer payload;
};

}
