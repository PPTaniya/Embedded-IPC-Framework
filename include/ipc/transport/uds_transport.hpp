#pragma once

#include "itransport.hpp"

#include <string>

namespace ipc
{

class UdsTransport : public ITransport
{
public:

    explicit UdsTransport(const std::string& path);

    bool createServer();

    bool connectServer();

    bool acceptClient();

    bool send(const Message& msg) override;

    bool receive(Message& msg) override;

    int getFd() const override;

private:

    int socketFd_;
    int clientFd_;

    std::string socketPath_;
};

}
