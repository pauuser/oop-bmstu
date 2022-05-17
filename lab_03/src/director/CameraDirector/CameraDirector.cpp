//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "CameraDirector.hpp"
#include "exceptions/director/DirectorException.hpp"

CameraDirector::CameraDirector(std::string name)
{
    _name = name;
}

void CameraDirectorCreator::_createDirector(std::string name)
{
    this->_director = std::make_shared<CameraDirector>(name);
    this->_director->setBuilder(BuilderSolution().getBuilderCreator("camera")->createBuilder());
    this->_director->setLoader(LoaderSolution().getLoaderCreator("camera")->createLoader(name));
}

std::shared_ptr<CameraDirector> CameraDirectorCreator::getDirector(std::string name)
{
    if (this->_director == nullptr)
    {
        this->_createDirector(name);
    }

    this->_director->setName(name);

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
    if (_loader == nullptr)
    {
        throw NoLoaderException(__FILE__, __LINE__);
    }

    if (_builder == nullptr)
    {
        throw NoBuilderException(__FILE__, __LINE__);
    }

    auto model = this->_loader->load(this->_builder);

    return model;
}

void CameraDirector::setName(std::string name)
{
    this->_name = name;
}

