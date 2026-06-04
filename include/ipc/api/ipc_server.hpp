#pragma once

#include "ipc/common/message.hpp"
#include "ipc/transport/uds_transport.hpp"

#include <memory>
#include <string>

namespace ipc
{

class IPCServer
{
public:

    explicit IPCServer(const std::string& socketPath);

    bool start();

    bool waitForClient();

    bool send(const Message& msg);

    bool receive(Message& msg);

private:

    std::unique_ptr<UdsTransport> transport_;
};

}
