//
// Created by Pavel Ivanov on 17.05.2022.
//

#ifndef LAB_03_BASEEXCEPTION_HPP
#define LAB_03_BASEEXCEPTION_HPP

#include <exception>
#include <string>
#include <ctime>
#include <chrono>

class BaseException : public std::exception
{
public:
    BaseException(const std::string& file, const std::size_t line, const std::string inf = "Some exception occured!")
    {
        time_t current_time = time(nullptr);
        auto local_time = localtime(&current_time);
        errinfo = "Time: " + std::string(asctime(local_time)) + " File: " + file + "\nLine : " + std::to_string(line) + " Message : " + inf;
    }
    virtual ~BaseException() = default;

    const char * what() const noexcept override
    {
        return errinfo.c_str();
    }
protected:
    std::string errinfo;
};




#endif//LAB_03_BASEEXCEPTION_HPP
