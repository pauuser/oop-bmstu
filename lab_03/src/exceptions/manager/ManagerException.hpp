//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_MANAGEREXCEPTION_HPP
#define LAB_03_MANAGEREXCEPTION_HPP

#include "exceptions/BaseException.hpp"

class ManagerException : public BaseException
{
public:
    ManagerException(const std::string& file, const std::size_t line, const std::string inf = "") :
            BaseException(file, line, "Error in manager! " + inf) {}
    ~ManagerException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class NoMainCameraException : public ManagerException
{
public:
    NoMainCameraException(const std::string& file, const std::size_t line, const std::string inf = "") :
            ManagerException(file, line, "No main camera! " + inf) {}
    ~NoMainCameraException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};


#endif//LAB_03_MANAGEREXCEPTION_HPP
