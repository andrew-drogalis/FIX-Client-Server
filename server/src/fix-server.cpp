// Copyright 2024, Andrew Drogalis
// GNU License

#include "fix-server.h"


namespace fixserver
{

FIXServer::FIXServer(int port, int max_events, int max_clients, int buffer_size)
    : port(port), max_events(max_events), max_clients(max_clients), buffer_size(buffer_size)
{
}

std::expected<bool, FIXServerException> FIXServer::start_server() noexcept
{
    
}


}// namespace fixserver
