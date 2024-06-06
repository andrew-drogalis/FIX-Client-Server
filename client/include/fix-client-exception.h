// Copyright 2024, Andrew Drogalis
// GNU License

#ifndef FIX_CLIENT_EXCEPTION_H
#define FIX_CLIENT_EXCEPTION_H

#include <stdexcept>// for runtime_error
#include <string>   // for basic_string

namespace fixclient
{

class FIXClientException : public std::runtime_error
{
  public:
    std::string message;
    std::string func_name;

    FIXClientException() = delete;

    FIXClientException(std::string const& func_name, std::string const& message);

    [[nodiscard]] char const* what() const noexcept override;

    [[nodiscard]] char const* where() const noexcept;
};

}// namespace fixclient

#endif
