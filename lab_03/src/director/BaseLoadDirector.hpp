//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_BASELOADDIRECTOR_HPP
#define LAB_03_BASELOADDIRECTOR_HPP

#include "builder/BaseBuilder.hpp"
#include "loader/BaseLoader.hpp"

class BaseLoadDirector
{
public:
    BaseLoadDirector() = default;
    virtual ~BaseLoadDirector() = default;

    virtual std::shared_ptr<Object> load() = 0;
    virtual void setBuilder(std::shared_ptr<BaseBuilder> builder) = 0;
    virtual void setLoader(std::shared_ptr<BaseLoader> loader) = 0;
};


#endif//LAB_03_BASELOADDIRECTOR_HPP
