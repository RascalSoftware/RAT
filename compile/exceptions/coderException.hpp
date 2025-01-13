#ifndef CODER_EXCEPTION_HPP
#define CODER_EXCEPTION_HPP

#include <stdexcept>

// Throws the appropriate std exception for the given error code defined 
// in the errorCodes.m 
namespace{
    void coderException(int errorCode, const char* msg)
    {
        if (errorCode == 1)
            throw std::invalid_argument(msg);
        else if (errorCode == 2)
            throw std::domain_error(msg);
        else
            throw std::runtime_error(msg);
    }
}
#endif // CODER_EXCEPTION_HPP