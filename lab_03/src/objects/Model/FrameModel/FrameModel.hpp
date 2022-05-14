//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_FRAMEMODEL_HPP
#define LAB_03_FRAMEMODEL_HPP

#include <memory>

#include "visitor/DrawVisitor/DrawVisitor.hpp"
#include "../FrameModelImplementation/FrameModelImplementation.hpp"
#include "../Model.hpp"

class FrameModel : public Model
{
public:
    FrameModel() = default;
    explicit FrameModel(std::shared_ptr<FrameModelImplementation> imp);
    ~FrameModel() override = default;

    void accept(std::shared_ptr<BaseVisitor> visitor) override;
    void transform(const Point& move_params, const Point& scale_params, const Point& rotate_params) override;

    friend void DrawVisitor::visit(const FrameModel& model);

protected:
    [[nodiscard]] std::shared_ptr<FrameModelImplementation> getImplementation() const;

private:
    std::shared_ptr<FrameModelImplementation> _implementation = nullptr;
};


#endif//LAB_03_FRAMEMODEL_HPP
