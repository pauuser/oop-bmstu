//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "DrawScene.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/DrawManager/DrawManager.hpp"

DrawScene::DrawScene(std::shared_ptr<BaseDrawer> &drawer) : _drawer(drawer) {}

void DrawScene::execute()
{
    auto scene_manager = SceneManagerCreator().getManager();
    auto draw_manager = DrawManagerCreator().getManager();

    draw_manager->setDrawer(this->_drawer);
    draw_manager->setCamera(scene_manager->getMainCamera());

    this->_drawer->clearScene();
    draw_manager->draw(scene_manager->getScene());
}