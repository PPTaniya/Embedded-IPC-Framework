#pragma once

#include <atomic>
#include <vector>

namespace ipc
{

class RingBuffer
{
public:

    explicit RingBuffer(size_t size);

    bool push(uint8_t value);

    bool pop(uint8_t& value);

private:

    std::vector<uint8_t> buffer_;

    std::atomic<size_t> head_;

    std::atomic<size_t> tail_;

    size_t size_;
};

}
