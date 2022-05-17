//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "ModelDirector.hpp"

ModelDirector::ModelDirector(std::string name)
{
    _name = name;
}

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

void ModelDirectorCreator::_createDirector(std::string name)
{
    this->_director = std::make_shared<ModelDirector>(name);
    this->_director->setBuilder(BuilderSolution().getBuilderCreator("model")->createBuilder());
    this->_director->setLoader(LoaderSolution().getLoaderCreator("model")->createLoader(name));
}

void ModelDirector::setName(std::string name)
{
    this->_name = name;
}

std::shared_ptr<ModelDirector> ModelDirectorCreator::getDirector(std::string name)
{
    if (this->_director == nullptr)
    {
        _createDirector(name);
    }

    this->_director->setName(name);

    return this->_director;
}
