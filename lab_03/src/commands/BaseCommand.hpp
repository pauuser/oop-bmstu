//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_BASECOMMAND_HPP
#define LAB_03_BASECOMMAND_HPP

#include <memory>

#include "managers/DrawManager/DrawManager.hpp"
#include "managers/LoadManager/LoadManager.hpp"
#include "managers/TransformManager/TransformManager.hpp"
#include "managers/SceneManager/SceneManager.hpp"

class BaseCommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() = default;

    virtual void execute() = 0;

protected:
    std::shared_ptr<DrawManager>      _drawmanager;
    std::shared_ptr<LoadManager>      _loadmanager;
    std::shared_ptr<TransformManager> _transformmanager;
    std::shared_ptr<SceneManager>     _scenemanager;

};

#endif//LAB_03_BASECOMMAND_HPP
