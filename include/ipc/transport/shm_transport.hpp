#pragma once

#include <string>

namespace ipc
{

class SharedMemoryTransport
{
public:

    bool create(const std::string& name,
                size_t size);

    bool write(const void* data,
               size_t size);

    bool read(void* data,
              size_t size);

private:

    int shmFd_;

    void* shmPtr_;

    size_t shmSize_;
};

}
