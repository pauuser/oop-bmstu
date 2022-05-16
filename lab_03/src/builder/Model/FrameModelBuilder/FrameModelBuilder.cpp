//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "FrameModelBuilder.hpp"

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
    // TODO: add exception if not built

    Point point(x, y, z);
    _modelimp->addPoint(point);
}

void FrameModelBuilder::buildEdge(std::size_t id1, std::size_t id2)
{
    // TODO: add exception if not built

    Edge edge(id1, id2);
    _modelimp->addEdge(edge);
}

std::shared_ptr<Object> FrameModelBuilder::get()
{
    return std::make_shared<FrameModel>(this->_modelimp);
}

void FrameModelBuilder::buildCenter(double x, double y, double z)
{
    // TODO: add exception if not built

    Point point(x, y, z);
    _modelimp->setCenter(point);
}
