#pragma once

#include <cstring>
#include <vector>
#include <type_traits>
#include <stdexcept>

namespace ipc
{

class Serializer
{
public:

    template<typename T>
    static std::vector<uint8_t> serialize(const T& obj)
    {
        static_assert(
            std::is_trivially_copyable_v<T>,
            "Serializer only supports trivially copyable types");

        std::vector<uint8_t> buffer(sizeof(T));

        std::memcpy(
            buffer.data(),
            &obj,
            sizeof(T));

        return buffer;
    }

    template<typename T>
    static T deserialize(const std::vector<uint8_t>& buffer)
    {
        static_assert(
            std::is_trivially_copyable_v<T>,
            "Serializer only supports trivially copyable types");

        if (buffer.size() != sizeof(T))
        {
            throw std::runtime_error(
                "Buffer size does not match object size");
        }

        T obj{};

        std::memcpy(
            &obj,
            buffer.data(),
            sizeof(T));

        return obj;
    }
};

} // namespace ipc
