// Copyright 2024, Andrew Drogalis
// GNU License

#include <iostream>// for operator<<, basic_ostream, cout

#include "tcp-server/include/main-utilities-server.hpp" for validateMainParameters
#include "fix-server.h"             // for TCPServer

int main(int argc, char* argv[])
{
    // User Default Values
    int PORT = 54000, MAX_CLIENTS = 10, MAX_EVENTS = 10, BUFFER_SIZE = 1024;

    if (! fixserver::validateMainParameters(argc, argv, PORT, MAX_CLIENTS, MAX_EVENTS, BUFFER_SIZE))
    {
        return 1;
    }
    // -------------------
    fixserver::FIXServer fixServ {PORT, MAX_CLIENTS, MAX_EVENTS, BUFFER_SIZE};

    auto fix_server_response = fixServ.start_server();

    if (! fix_server_response)
    {
        std::cout << "Error Location: " << fix_server_response.error().where() << '\n';
        std::cout << fix_server_response.error().what() << '\n';
        return 1;
    }

    std::cout << "\nConnection Closed Successfully.\n";
    // -------------------
    return 0;
}
