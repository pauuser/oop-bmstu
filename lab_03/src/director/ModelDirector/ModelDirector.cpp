//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "ModelDirector.hpp"

void ModelDirector::setBuilder(std::shared_ptr<BaseBuilder> builder)
{
    this->_builder = builder;
}

void ModelDirector::setLoader(std::shared_ptr<BaseLoader> loader)
{
    this->_loader = loader;
}

std::shared_ptr<Object> ModelDirector::load()
{
    // TODO: add exception if loader or builder not set
    auto model = this->_loader->load(this->_builder);

    return model;
}

void ModelDirectorCreator::_createDirector()
{
    this->_director = std::make_shared<ModelDirector>();
}

std::shared_ptr<ModelDirector> ModelDirectorCreator::getDirector()
{
    if (this->_director == nullptr)
    {
        _createDirector();
    }

    return this->_director;
}
