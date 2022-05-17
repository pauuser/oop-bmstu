//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_CONFIGURATIONEXCEPTION_HPP
#define LAB_03_CONFIGURATIONEXCEPTION_HPP

#include "exceptions/BaseException.hpp"

class ConfigurationException : public BaseException
{
public:
    ConfigurationException(const std::string& file, const std::size_t line, const std::string inf = "") :
            BaseException(file, line, "Configuration error! " + inf) {}
    ~ConfigurationException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class NoFileException : public ConfigurationException
{
public:
    NoFileException(const std::string& file, const std::size_t line, const std::string inf = "") :
           ConfigurationException(file, line, "No file! " + inf) {}
    ~NoFileException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class ReadException : public ConfigurationException
{
public:
    ReadException(const std::string& file, const std::size_t line, const std::string inf = "") :
           ConfigurationException(file, line, "Reading error! " + inf) {}
    ~ReadException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class NoConfigurationException: public ConfigurationException
{
public:
    NoConfigurationException(const std::string& file, const std::size_t line, const std::string inf = "") :
             ConfigurationException(file, line, "No configuration! " + inf) {}
    ~NoConfigurationException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};


#endif//LAB_03_CONFIGURATIONEXCEPTION_HPP
