//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_BASECAMERABUILDER_HPP
#define LAB_03_BASECAMERABUILDER_HPP

#include "builder/BaseBuilder.hpp"

class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() override = default;

    virtual void buildPosition(double x, double y, double z) = 0;
    virtual void buildAngle(double ax, double ay, double az) = 0;
};


#endif//LAB_03_BASECAMERABUILDER_HPP
