//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "AddCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "objects/Camera/BaseCamera.hpp"
#include "objects/Camera/Camera/Camera.hpp"

AddCamera::AddCamera(double posx, double posy, double posz, double ax, double ay, double az): _posx(posx), _posy(posy), _posz(posz),
                                                             _ax(ax), _ay(ay), _az(az){}

void AddCamera::execute()
{
    auto camera = CameraCreator(Point{_posx, _posy, _posz}, _ax, _ay, _az).create();
    SceneManagerCreator().getManager()->addObject(camera);
}
