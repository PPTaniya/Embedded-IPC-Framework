#include "ipc/transport/uds_transport.hpp"

#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <cstring>
#include <iostream>

namespace ipc
{

UdsTransport::UdsTransport(const std::string& path)
    : socketFd_(-1),
      clientFd_(-1),
      socketPath_(path)
{
}

bool UdsTransport::createServer()
{
    socketFd_ = socket(AF_UNIX, SOCK_STREAM, 0);

    if (socketFd_ < 0)
        return false;

    sockaddr_un addr{};

    addr.sun_family = AF_UNIX;

    std::strncpy(addr.sun_path,
                 socketPath_.c_str(),
                 sizeof(addr.sun_path) - 1);

    unlink(socketPath_.c_str());

    if (bind(socketFd_,
             reinterpret_cast<sockaddr*>(&addr),
             sizeof(addr)) < 0)
    {
        return false;
    }

    if (listen(socketFd_, 5) < 0)
        return false;

    return true;
}

bool UdsTransport::connectServer()
{
    socketFd_ = socket(AF_UNIX, SOCK_STREAM, 0);

    sockaddr_un addr{};

    addr.sun_family = AF_UNIX;

    std::strncpy(addr.sun_path,
                 socketPath_.c_str(),
                 sizeof(addr.sun_path) - 1);

    return connect(socketFd_,
                   reinterpret_cast<sockaddr*>(&addr),
                   sizeof(addr)) == 0;
}

bool UdsTransport::acceptClient()
{
    clientFd_ = accept(socketFd_, nullptr, nullptr);

    return clientFd_ >= 0;
}

bool UdsTransport::send(const Message& msg)
{
    int fd = (clientFd_ >= 0) ? clientFd_ : socketFd_;

    if (::write(fd,
                &msg.header,
                sizeof(msg.header)) < 0)
    {
        return false;
    }

    if (::write(fd,
                msg.payload.data(),
                msg.payload.size()) < 0)
    {
        return false;
    }

    return true;
}

bool UdsTransport::receive(Message& msg)
{
    int fd = (clientFd_ >= 0) ? clientFd_ : socketFd_;

    if (::read(fd,
               &msg.header,
               sizeof(msg.header)) <= 0)
    {
        return false;
    }

    msg.payload.resize(msg.header.size);

    if (::read(fd,
               msg.payload.data(),
               msg.header.size) <= 0)
    {
        return false;
    }

    return true;
}

int UdsTransport::getFd() const
{
    return (clientFd_ >= 0)
           ? clientFd_
           : socketFd_;
}

}
