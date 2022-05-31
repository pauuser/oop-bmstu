//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_DRAWSCENE_HPP
#define LAB_03_DRAWSCENE_HPP

#include <memory>

#include "commands/scene/BaseSceneCommand.hpp"
#include "../../gui/drawer/BaseDrawer.hpp"
#include "managers/DrawManager/DrawManager.hpp"

class DrawScene : public BaseSceneCommand
{
    using Action =  void(DrawManager::*)();
public:
    DrawScene() = delete;
    DrawScene(std::shared_ptr<BaseDrawer>& drawer);
    ~DrawScene() override = default;

    void execute() override;

private:
    Action _act;

    std::shared_ptr<BaseDrawer> _drawer;

    std::shared_ptr<DrawManager> _manager;
};


#endif//LAB_03_DRAWSCENE_HPP
