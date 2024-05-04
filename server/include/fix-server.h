// Copyright 2024, Andrew Drogalis
// GNU License

#ifndef FIX_SERVER_H
#define FIX_SERVER_H

#include <expected>// for expected

#include "fix-server-exception.h"// for FIXServerException

namespace fixserver
{

class FIXServer
{

  public:
    FIXServer() = default;

    FIXServer(int port, int max_events, int max_clients, int buffer_size);

    [[nodiscard]] std::expected<bool, FIXServerException> start_server() noexcept;

  private:
    int port, max_events, max_clients, buffer_size;
};

}// namespace fixserver

#endif
