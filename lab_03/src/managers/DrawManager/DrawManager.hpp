//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_DRAWMANAGER_HPP
#define LAB_03_DRAWMANAGER_HPP

#include <memory>

#include "../../gui/drawer/BaseDrawer.hpp"
#include "managers/BaseManager/BaseManager.hpp"
#include "objects/Camera/Camera.hpp"

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;

    DrawManager(const DrawManager& manager) = delete;
    DrawManager& operator=(const DrawManager& manager) = delete;

    ~DrawManager() override = default;

    void draw();
    void setDrawer(const std::shared_ptr<BaseDrawer>& drawer);
    void setCamera(const std::shared_ptr<Camera>& camera);

private:
    std::shared_ptr<BaseDrawer> _drawer = nullptr;
    std::shared_ptr<Camera>     _camera = nullptr;
};

class DrawManagerCreator
{
public:
    std::shared_ptr<DrawManager> getManager(const std::shared_ptr<BaseDrawer>& drawer);

private:
    void _createManager();
    std::shared_ptr<DrawManager> _manager = nullptr;
};

#endif//LAB_03_DRAWMANAGER_HPP
