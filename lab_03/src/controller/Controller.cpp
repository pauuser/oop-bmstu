//
// Created by Pavel Ivanov on 25.05.2022.
//

#include "Controller.hpp"
#include "director/CameraDirector/CameraDirector.hpp"

std::shared_ptr<Controller> Controller::getInstance()
{
    static std::shared_ptr<Controller> controller(new Controller());

    return controller;
}

void Controller::addCamera(double posx, double posy, double posz,
                           double ax,   double ay,   double az)
{
    auto camera = CameraCreator(Point{posx, posy, posz}, ax, ay, az).create();
    SceneManagerCreator().getManager()->addObject(camera);
}

void Controller::CountCamera(std::shared_ptr<size_t> &size)
{
    *size = SceneManagerCreator().getManager()->getCameraCount();
}

void Controller::LoadCamera(const std::string &name)
{
    auto director = CameraDirectorCreator().getDirector(name);
    LoadManagerCreator().getManager(director)->load();
}

void Controller::MoveCamera(std::size_t id, const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    TransformManagerCreator().getManager()->transformInvisible(id, move_params, scale_params, rotate_params);
}

void Controller::RemoveCamera(std::size_t id)
{
    SceneManagerCreator().getManager()->removeInvisible(id);
}

void Controller::SetCamera(std::size_t id)
{
    SceneManagerCreator().getManager()->setMainCamera(id);
}

void Controller::AddModel(std::shared_ptr<Object> obj)
{
    SceneManagerCreator().getManager()->addObject(obj);
}

void Controller::CountModel(std::shared_ptr<size_t> &size)
{
    *(size) = SceneManagerCreator().getManager()->getModelCount();
}

void Controller::LoadModel(std::string name)
{
    auto director = ModelDirectorCreator().getDirector(name);
    LoadManagerCreator().getManager(director)->load();
}

void Controller::MoveModel(std::size_t id, double dx, double dy, double dz)
{
    Point move{ dx, dy, dz }, scale{ 1, 1, 1 }, rotate{ 0, 0, 0 };
    TransformManagerCreator().getManager()->transformVisible(id, move, scale, rotate);
}

void Controller::RemoveModel(std::size_t id)
{
    SceneManagerCreator().getManager()->removeVisible(id);
}

void Controller::RotateModel(std::size_t id, double ax, double ay, double az)
{
    Point move{ 0, 0, 0 }, scale{ 1, 1, 1 }, rotate{ ax, ay, az };
    TransformManagerCreator().getManager()->transformVisible(id, move, scale, rotate);
}

void Controller::ScaleModel(std::size_t id, double kx, double ky, double kz)
{
    Point move{ 0, 0, 0 }, scale{ kx, ky, kz }, rotate{ 0, 0, 0 };
    TransformManagerCreator().getManager()->transformVisible(id, move, scale, rotate);
}

void Controller::TransformModel(std::size_t id, const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    TransformManagerCreator().getManager()->transformVisible(id, move_params, scale_params, rotate_params);
}

void Controller::DrawScene(std::shared_ptr<BaseDrawer> &drawer)
{
    DrawManagerCreator().getManager(drawer)->draw();
}

void Controller::RegisterTextConfiguration(std::string filename)
{
    auto solution = ConfigurationSolution();
    solution.registration(TextConfigurationCreator(filename).getConfiguration());
    solution.createCreator()->register_framework();
}