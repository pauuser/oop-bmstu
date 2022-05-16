//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_FRAMEMODELBUILDER_HPP
#define LAB_03_FRAMEMODELBUILDER_HPP

#include "builder/Model/BaseModelBuilder.hpp"
#include "objects/Model/FrameModel/FrameModel.hpp"
#include "objects/Model/FrameModelImplementation/FrameModelImplementation.hpp"
#include "objects/Point/Point.hpp"
#include "objects/Edge/Edge.hpp"

class FrameModelBuilder : public BaseModelBuilder
{
public:
    FrameModelBuilder() = default;
    ~FrameModelBuilder() override = default;

    void build() override;
    bool is_built() override;
    void reset() override;

    std::shared_ptr<Object> get() override;

    void buildPoint(double x, double y, double z);
    void buildEdge(std::size_t id1, std::size_t id2);
    void buildCenter(double x, double y, double z);

private:
    std::shared_ptr<FrameModelImplementation> _modelimp = nullptr;
};


#endif//LAB_03_FRAMEMODELBUILDER_HPP
