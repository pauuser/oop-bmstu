//
// Created by Pavel Ivanov on 13.05.2022.
//

#include "SceneManager.hpp"
#include "exceptions/manager/ManagerException.hpp"

SceneManager::SceneManager() : _scene(std::make_shared<Scene>()) {}

std::shared_ptr<Camera> SceneManager::getMainCamera()
{
    if (_main_camera.lock() == nullptr)
    {
        throw NoMainCameraException(__FILE__, __LINE__);
    }

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
    static auto manager = std::make_shared<SceneManager>();
    this->_manager = manager;
}

