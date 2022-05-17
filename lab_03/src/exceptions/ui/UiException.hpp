//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_UIEXCEPTION_HPP
#define LAB_03_UIEXCEPTION_HPP

#include "exceptions/BaseException.hpp"

class UiException : public BaseException
{
public:
    UiException(const std::string& file, const std::size_t line, const std::string inf = "") :
           BaseException(file, line, "Error happened from UI call! " + inf) {}
    ~UiException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class NoModelException : public UiException
{
public:
    NoModelException(const std::string& file, const std::size_t line, const std::string inf = "") :
            UiException(file, line, "No models yet! " + inf) {}
    ~NoModelException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class FewModels : public UiException
{
public:
    FewModels(const std::string& file, const std::size_t line, const std::string inf = "") :
            UiException(file, line, "Model not found! " + inf) {}
    ~FewModels() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class FewCameras : public UiException
{
public:
    FewCameras(const std::string& file, const std::size_t line, const std::string inf = "") :
             UiException(file, line, "Camera not found! " + inf) {}
    ~FewCameras() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

class NoCameraException : public UiException
{
public:
    NoCameraException(const std::string& file, const std::size_t line, const std::string inf = "") :
            UiException(file, line, "No models yet! " + inf) {}
    ~NoCameraException() override = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
};

#endif//LAB_03_UIEXCEPTION_HPP
