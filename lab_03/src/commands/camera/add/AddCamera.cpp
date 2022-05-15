//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "AddCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

AddCamera::AddCamera(double posx, double posy, double posz): _posx(posx), _posy(posy), _posz(posz) {}

void AddCamera::execute()
{
    Point camera_position(_posx, _posy, _posz);

    auto scene_manager = SceneManagerCreator().getManager();
    auto scene = scene_manager->getScene();

    auto camera = std::make_shared<Camera>(camera_position, 0, 0, 0);
    scene->addObject(camera);

    scene_manager->setMainCamera(scene->end() - 1);
}
