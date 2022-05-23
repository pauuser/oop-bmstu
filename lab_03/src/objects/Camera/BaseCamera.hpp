//
// Created by Pavel Ivanov on 23.05.2022.
//

#ifndef LAB_03_BASECAMERA_HPP
#define LAB_03_BASECAMERA_HPP

#include <memory>
#include "objects/Object.hpp"

class BaseCamera : public InvisibleObject
{
};

class BaseCameraCreator
{
public:
    BaseCameraCreator() = default;
    virtual ~BaseCameraCreator() = default;

    virtual std::shared_ptr<BaseCamera> create() = 0;
};


#endif//LAB_03_BASECAMERA_HPP
