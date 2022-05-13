//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_FRAMEMODEL_HPP
#define LAB_03_FRAMEMODEL_HPP

#include "../Model.hpp"
#include "../FrameModelImplementation/FrameModelImplementation.hpp"

#include "visitor/BaseVisitor.h"

class FrameModel : public Model
{
public:
    FrameModel() = default;
    explicit FrameModel(std::shared_ptr<FrameModelImplementation> imp);
    ~FrameModel() override = default;

    void accept(std::shared_ptr<BaseVisitor> visitor) override;
    void transform(const Point& move_params, const Point& scale_params, const Point& rotate_params) override;

private:
    std::shared_ptr<FrameModelImplementation> _implementation = nullptr;
};


#endif//LAB_03_FRAMEMODEL_HPP
