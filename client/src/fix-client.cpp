// Copyright 2024, Andrew Drogalis
// GNU License

#include "fix-client.h"


namespace fixclient
{

FIXClient::FIXClient(std::string ip_address, int port, int buffer_size) : ip_address(ip_address), port(port), buffer_size(buffer_size) {}

std::expected<bool, FIXClientException> FIXClient::start_client() noexcept
{
    
}



}// namespace fixclient
