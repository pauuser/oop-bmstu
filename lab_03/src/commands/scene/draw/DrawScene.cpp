//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "DrawScene.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/DrawManager/DrawManager.hpp"

DrawScene::DrawScene(std::shared_ptr<BaseDrawer> &drawer) : _drawer(drawer) {}

void DrawScene::execute(std::shared_ptr<Controller> controller)
{
    controller->DrawScene(_drawer);
}