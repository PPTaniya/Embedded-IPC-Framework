#include "ipc/core/event_loop.hpp"

#include <sys/epoll.h>
#include <unistd.h>

namespace ipc
{

EventLoop::EventLoop()
{
    epollFd_ = epoll_create1(0);
}

EventLoop::~EventLoop()
{
    close(epollFd_);
}

void EventLoop::addFd(int fd,
                      std::function<void()> callback)
{
    epoll_event ev{};

    ev.events = EPOLLIN;

    ev.data.fd = fd;

    epoll_ctl(epollFd_,
              EPOLL_CTL_ADD,
              fd,
              &ev);

    callbacks_[fd] = callback;
}

void EventLoop::run()
{
    constexpr int MAX_EVENTS = 10;

    epoll_event events[MAX_EVENTS];

    while (true)
    {
        int n = epoll_wait(epollFd_,
                           events,
                           MAX_EVENTS,
                           -1);

        for (int i = 0; i < n; ++i)
        {
            int fd = events[i].data.fd;

            callbacks_[fd]();
        }
    }
}

}
