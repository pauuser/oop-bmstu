//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_BUILDEREXCEPTION_HPP
#define LAB_03_BUILDEREXCEPTION_HPP

#include "exceptions/BaseException.hpp"

class BuilderException : public BaseException
{
public:
    BuilderException(const std::string& file, const std::size_t line, const std::string inf = "") :
           BaseException(file, line, "Error while building an object! " + inf) {}
    ~BuilderException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class BuildNotStartedException : public BuilderException
{
public:
    BuildNotStartedException(const std::string& file, const std::size_t line, const std::string inf = "") :
            BuilderException(file, line, "Build not started! " + inf) {}
    ~BuildNotStartedException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class BuilderNotRegisteredException : public BuilderException
{
public:
    BuilderNotRegisteredException(const std::string& file, const std::size_t line, const std::string inf = "") :
            BuilderException(file, line, "No fitting registered builder! " + inf) {}
    ~BuilderNotRegisteredException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};


#endif//LAB_03_BUILDEREXCEPTION_HPP
