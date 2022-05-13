//
// Created by Pavel Ivanov on 13.05.2022.
//

#include "SceneManager.hpp"

SceneManager::SceneManager() : _scene(std::make_shared<Scene>()) {}

std::shared_ptr<Camera> SceneManager::getMainCamera()
{
    // TODO: add exception if nullptr

    return this->_main_camera.lock();
}

void SceneManager::setMainCamera(const Iterator &it)
{
    this->_main_camera = std::dynamic_pointer_cast<Camera>(*it);
}

void SceneManager::setScene(std::shared_ptr<Scene> &scene)
{
    this->_scene = scene;
}

std::shared_ptr<Scene> SceneManager::getScene()
{
    return this->_scene;
}

std::shared_ptr<SceneManager> SceneManagerCreator::getManager()
{
    if (this->_manager == nullptr)
    {
        this->_createManager();
    }

    return this->_manager;
}

void SceneManagerCreator::_createManager()
{
    this->_manager = std::make_shared<SceneManager>();
}

