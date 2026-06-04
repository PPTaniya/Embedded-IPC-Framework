#include "ipc/api/ipc_client.hpp"

namespace ipc
{

IPCClient::IPCClient(const std::string& socketPath)
{
    transport_ =
        std::make_unique<UdsTransport>(socketPath);
}

bool IPCClient::connect()
{
    return transport_->connectServer();
}

bool IPCClient::send(const Message& msg)
{
    return transport_->send(msg);
}

bool IPCClient::receive(Message& msg)
{
    return transport_->receive(msg);
}

}
