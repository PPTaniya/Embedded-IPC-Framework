#include "ipc/api/ipc_server.hpp"

namespace ipc
{

IPCServer::IPCServer(const std::string& socketPath)
{
    transport_ =
        std::make_unique<UdsTransport>(socketPath);
}

bool IPCServer::start()
{
    return transport_->createServer();
}

bool IPCServer::waitForClient()
{
    return transport_->acceptClient();
}

bool IPCServer::send(const Message& msg)
{
    return transport_->send(msg);
}

bool IPCServer::receive(Message& msg)
{
    return transport_->receive(msg);
}

}
