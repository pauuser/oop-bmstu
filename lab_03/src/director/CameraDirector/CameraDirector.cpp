//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "CameraDirector.hpp"

void CameraDirectorCreator::_createDirector()
{
    this->_director = std::make_shared<CameraDirector>();
}

std::shared_ptr<CameraDirector> CameraDirectorCreator::getDirector()
{
    if (this->_director == nullptr)
    {
        this->_createDirector();
    }

    return this->_director;
}

void CameraDirector::setBuilder(std::shared_ptr<BaseBuilder> builder)
{
    this->_builder = builder;
}

void CameraDirector::setLoader(std::shared_ptr<BaseLoader> loader)
{
    this->_loader = loader;
}

std::shared_ptr<Object> CameraDirector::load()
{
    // TODO: add exception if no loader or builder

    auto model = this->_loader->load(this->_builder);

    return model;
}