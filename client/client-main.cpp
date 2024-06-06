// Copyright 2024, Andrew Drogalis
// GNU License

#include <iostream>// for operator<<, basic_ostream, cout
#include <string>  // for basic_string

#include "tcp-client/include/tcp-client.h" for validateMainParameters
#include "tcp-client/include/main-utilities-client.hpp" for TCPClient

int main(int argc, char* argv[])
{
    std::string IP_ADDRESS = "127.0.0.1";
    int PORT = 54000, BUFFER_SIZE = 1024;

    if (! fixclient::validateMainParameters(argc, argv, IP_ADDRESS, PORT, BUFFER_SIZE))
    {
        return 1;
    }
    // -------------------
    fixclient::FIXClient fixClient {IP_ADDRESS, PORT, BUFFER_SIZE};

    auto fix_client_response = fixClient.start_client();

    if (! fix_client_response)
    {
        std::cout << "Error Location: " << fix_client_response.error().where() << '\n';
        std::cout << fix_client_response.error().what() << '\n';
        return 1;
    }

    std::cout << "\nConnection Closed Successfully.\n";
    // -------------------
    return 0;
}
