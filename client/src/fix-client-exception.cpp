// Copyright 2024, Andrew Drogalis
// GNU License

#include <fix-client-exception.h>

#include <stdexcept>// for runtime_error
#include <string>   // for basic_string

namespace fixclient
{

FIXClientException::FIXClientException(std::string const& func_name, std::string const& message)
    : std::runtime_error {message}, func_name(func_name), message(message)
{
}

char const* FIXClientException::what() const noexcept { return message.c_str(); }

char const* FIXClientException::where() const noexcept { return func_name.c_str(); }

}// namespace fixclient
