//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "DrawManager.hpp"
#include "scene/Scene.hpp"

void DrawManager::draw(const std::shared_ptr<Scene> scene)
{
    auto visitor = std::make_shared<DrawVisitor>(this->_drawer, this->_camera);

    for (auto it = scene->begin(); it < scene->end(); it++)
    {
        auto obj = *it;
        obj->accept(visitor);
    }
}

void DrawManager::setDrawer(const std::shared_ptr<BaseDrawer> drawer)
{
    this->_drawer = std::move(drawer);
}

void DrawManager::setCamera(const std::shared_ptr<Camera> camera)
{
    this->_camera = std::move(camera);
}

void DrawManagerCreator::_createManager()
{
    static auto manager = std::make_shared<DrawManager>();
    this->_manager = manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::getManager()
{
    if (this->_manager == nullptr)
    {
        _createManager();
    }

    return this->_manager;
}