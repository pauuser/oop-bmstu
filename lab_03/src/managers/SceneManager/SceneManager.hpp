//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_SCENEMANAGER_HPP
#define LAB_03_SCENEMANAGER_HPP

#include <memory>

#include "managers/BaseManager/BaseManager.hpp"
#include "../../scene/Scene.hpp"
#include "../../objects/Camera/Camera.hpp"

class SceneManager : public BaseManager
{
public:
    SceneManager();

    SceneManager(const SceneManager& manager) = delete; // Making object un-copy-able
    SceneManager& operator=(const SceneManager& manager) = delete;

    ~SceneManager() override = default;

    std::shared_ptr<Scene> getScene();
    void setScene(std::shared_ptr<Scene>& scene);

    std::shared_ptr<Camera> getMainCamera();
    void setMainCamera(const Iterator& it);

private:
    std::shared_ptr<Scene> _scene = nullptr;
    std::weak_ptr<Camera>  _main_camera;
};

class SceneManagerCreator
{
public:
    std::shared_ptr<SceneManager> getManager();

private:
    void _createManager();
    std::shared_ptr<SceneManager> _manager = nullptr;
};

#endif//LAB_03_SCENEMANAGER_HPP
