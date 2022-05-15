//
// Created by Pavel Ivanov on 13.05.2022.
//

#include "Scene.hpp"

Scene::Scene(): _objects(std::make_shared<Composite>()) {}

void Scene::addObject(const std::shared_ptr<Object> &object)
{
    if (object->isVisible())
    {
        this->_model_count += 1;
    }
    else
    {
        this->_camera_count += 1;
    }

    this->_objects->add(object);
}

void Scene::removeObject(const Iterator &it)
{
    this->_objects->remove(it);
}

Iterator Scene::begin()
{
    return this->_objects->begin();
}

Iterator Scene::end()
{
    return this->_objects->end();
}

ConstIterator Scene::cbegin() const
{
    return this->_objects->cbegin();
}

ConstIterator Scene::cend() const
{
    return this->_objects->cend();
}

ConstIterator Scene::begin() const
{
    return this->_objects->cbegin();
}

ConstIterator Scene::end() const
{
    return this->_objects->cend();
}

size_t Scene::getModelCount() const
{
    return this->_model_count;
}

size_t Scene::getCameraCount() const
{
    return this->_camera_count;
}

