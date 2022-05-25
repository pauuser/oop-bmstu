//
// Created by Pavel Ivanov on 25.05.2022.
//

#ifndef LAB_03_CONTROLLER_HPP
#define LAB_03_CONTROLLER_HPP

#include <memory>
#include <string>

#include "managers/DrawManager/DrawManager.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"
#include "director/ModelDirector/ModelDirector.hpp"
#include "configuration/Solution/ConfigurationSolution.hpp"
#include "configuration/TextConfiguration/TextConfiguration.hpp"


class Controller
{
public:
    Controller(Controller &) = delete;
    Controller(const Controller &) = delete;
    ~Controller() = default;

    static std::shared_ptr<Controller> getInstance();

    void addCamera(double posx, double posy, double posz,
                   double ax,   double ay,   double az);

    void CountCamera(std::shared_ptr<size_t>& size);
    void LoadCamera(const std::string& name);
    void MoveCamera(std::size_t id, const Point &move_params, const Point &scale_params, const Point &rotate_params);
    void RemoveCamera(std::size_t id);
    void SetCamera(std::size_t id);

    void AddModel(std::shared_ptr<Object> obj);
    void CountModel(std::shared_ptr<size_t>& size);
    void LoadModel(std::string name);
    void MoveModel(std::size_t id, double dx, double dy, double dz);
    void RemoveModel(std::size_t id);
    void RotateModel(std::size_t id, double ax, double ay, double az);
    void ScaleModel(std::size_t id, double kx, double ky, double kz);
    void TransformModel(std::size_t id, const Point &move_params, const Point &scale_params, const Point &rotate_params);

    void DrawScene(std::shared_ptr<BaseDrawer> &drawer);
    void RegisterTextConfiguration(std::string filename);

private:
    Controller() = default;
};


#endif//LAB_03_CONTROLLER_HPP
