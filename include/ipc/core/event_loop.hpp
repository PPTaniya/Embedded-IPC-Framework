#pragma once

#include <functional>
#include <unordered_map>

namespace ipc
{

class EventLoop
{
public:

    EventLoop();

    ~EventLoop();

    void addFd(int fd,
               std::function<void()> callback);

    void run();

private:

    int epollFd_;

    std::unordered_map<int,
    std::function<void()>> callbacks_;
};

}
