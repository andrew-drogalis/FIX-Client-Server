// Copyright 2024, Andrew Drogalis
// GNU License

#ifndef FIX_SERVER_EXCEPTION_H
#define FIX_SERVER_EXCEPTION_H

#include <stdexcept>// for runtime_error
#include <string>   // for basic_string

namespace fixserver
{

class FIXServerException : public std::runtime_error
{
  public:
    std::string message;
    std::string func_name;

    FIXServerException() = delete;

    FIXServerException(std::string const& func_name, std::string const& message);

    [[nodiscard]] char const* what() const noexcept override;

    [[nodiscard]] char const* where() const noexcept;
};

}// namespace fixserver

#endif
