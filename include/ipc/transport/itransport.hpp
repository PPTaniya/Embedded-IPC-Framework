#pragma once

#include "ipc/common/message.hpp"

namespace ipc
{

class ITransport
{
public:

    virtual ~ITransport() = default;

    virtual bool send(
        const Message& msg) = 0;

    virtual bool receive(
        Message& msg) = 0;

    virtual int getFd() const = 0;
};

} // namespace ipc
