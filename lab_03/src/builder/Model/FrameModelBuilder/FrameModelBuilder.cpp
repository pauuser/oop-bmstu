//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "FrameModelBuilder.hpp"
#include "exceptions/builder/BuilderException.hpp"

void FrameModelBuilder::build()
{
    _modelimp = std::make_shared<FrameModelImplementation>();
}

bool FrameModelBuilder::is_built()
{
    return _modelimp == nullptr;
}

void FrameModelBuilder::reset()
{
    _modelimp.reset();
}

void FrameModelBuilder::buildPoint(double x, double y, double z)
{
    if (_modelimp == nullptr)
    {
        throw BuildNotStartedException(__FILE__, __LINE__, "...building FrameModel.");
    }

    Point point(x, y, z);
    _modelimp->addPoint(point);
}

void FrameModelBuilder::buildEdge(std::size_t id1, std::size_t id2)
{
    if (_modelimp == nullptr)
    {
        throw BuildNotStartedException(__FILE__, __LINE__, "...building FrameModel.");
    }

    Edge edge(id1, id2);
    _modelimp->addEdge(edge);
}

std::shared_ptr<Object> FrameModelBuilder::get()
{
    return std::make_shared<FrameModel>(this->_modelimp);
}

void FrameModelBuilder::buildCenter(double x, double y, double z)
{
    if (_modelimp == nullptr)
    {
        throw BuildNotStartedException(__FILE__, __LINE__, "...building FrameModel.");
    }

    Point point(x, y, z);
    _modelimp->setCenter(point);
}

std::shared_ptr<BaseBuilder> FrameModelBuilderCreator::createBuilder()
{
    return std::make_shared<FrameModelBuilder>();
}