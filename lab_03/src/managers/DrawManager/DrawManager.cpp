//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "DrawManager.hpp"
#include "scene/Scene.hpp"
#include "managers/SceneManager/SceneManager.hpp"

void DrawManager::draw()
{
    auto scene_manager = SceneManagerCreator().getManager();
    auto scene = scene_manager->getScene();
    this->setCamera(scene_manager->getMainCamera());

    this->_drawer->clearScene();

    std::shared_ptr<BaseVisitor> visitor = DrawVisitorCreator(this->_drawer, this->_camera).create();

    for (auto it = scene->begin(); it < scene->end(); it++)
    {
        auto obj = *it;
        obj->accept(visitor);
    }
}

void DrawManager::setDrawer(const std::shared_ptr<BaseDrawer>& drawer)
{
    this->_drawer = drawer;
}

void DrawManager::setCamera(const std::shared_ptr<Camera>& camera)
{
    this->_camera = camera;
}

void DrawManagerCreator::_createManager()
{
    static auto manager = std::make_shared<DrawManager>();
    this->_manager = manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::getManager(const std::shared_ptr<BaseDrawer>& drawer)
{
    if (this->_manager == nullptr)
    {
        _createManager();
    }

    this->_manager->setDrawer(drawer);

    return this->_manager;
}