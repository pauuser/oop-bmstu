//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "AddCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

AddCamera::AddCamera(double posx, double posy, double posz, double ax, double ay, double az): _posx(posx), _posy(posy), _posz(posz),
                                                             _ax(ax), _ay(ay), _az(az){}

void AddCamera::execute()
{
    Point camera_position(_posx, _posy, _posz);

    auto scene_manager = SceneManagerCreator().getManager();
    auto scene = scene_manager->getScene();

    // TODO: fix here

    auto camera = std::make_shared<Camera>(camera_position, _ax, _ay, _az);
    scene->addObject(camera);

    auto it = scene->end() - 1;

    scene_manager->setMainCamera(it);
}
