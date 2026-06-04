#pragma once

#include "ipc/common/message.hpp"
#include "ipc/transport/uds_transport.hpp"

#include <memory>
#include <string>

namespace ipc
{

class IPCClient
{
public:

    explicit IPCClient(const std::string& socketPath);

    bool connect();

    bool send(const Message& msg);

    bool receive(Message& msg);

private:

    std::unique_ptr<UdsTransport> transport_;
};

}
