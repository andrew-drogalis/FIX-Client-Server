// Copyright 2024, Andrew Drogalis
// GNU License

#ifndef FIX_CLIENT_H
#define FIX_CLIENT_H

#include <expected>// for expected
#include <string>  // for basic_string

#include "fix-client-exception.h"// for FIXClientException

namespace fixclient
{

class FIXClient
{

  public:
    FIXClient() = default;

    FIXClient(std::string ip_address, int port, int buffer_size);

    [[nodiscard]] std::expected<bool, FIXClientException> start_client() noexcept;

    void clean_up_socket(int socket_FD) noexcept;

  private:
    std::string ip_address;
    int port, buffer_size;
};

}// namespace fixclient

#endif
