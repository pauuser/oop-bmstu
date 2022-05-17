//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_DIRECTOREXCEPTION_HPP
#define LAB_03_DIRECTOREXCEPTION_HPP

#include "exceptions/BaseException.hpp"

class DirectorException : public BaseException
{
public:
    DirectorException(const std::string& file, const std::size_t line, const std::string inf = "") :
            BaseException(file, line, "Error in director! " + inf) {}
    ~DirectorException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class NoLoaderException : public DirectorException
{
public:
    NoLoaderException(const std::string& file, const std::size_t line, const std::string inf = "") :
            DirectorException(file, line, "No loader! " + inf) {}
    ~NoLoaderException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class NoBuilderException : public DirectorException
{
public:
    NoBuilderException(const std::string& file, const std::size_t line, const std::string inf = "") :
             DirectorException(file, line, "No builder! " + inf) {}
    ~NoBuilderException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};


#endif//LAB_03_DIRECTOREXCEPTION_HPP
