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

    void buildPoint(double x, double y, double z) override;
    void buildEdge(std::size_t id1, std::size_t id2) override;
    void buildCenter(double x, double y, double z) override;

private:
    std::shared_ptr<FrameModelImplementation> _modelimp = nullptr;
};

class FrameModelBuilderCreator : public BuilderCreator
{
public:
    FrameModelBuilderCreator() = default;
    ~FrameModelBuilderCreator() override = default;

    std::shared_ptr<BaseBuilder> createBuilder() override;
};

#endif//LAB_03_FRAMEMODELBUILDER_HPP
