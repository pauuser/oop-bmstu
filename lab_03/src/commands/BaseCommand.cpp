//
// Created by Pavel Ivanov on 25.05.2022.
//

#include "BaseCommand.hpp"

BaseCommand::BaseCommand()
{
    _drawmanager      = DrawManagerCreator().getManager();
    _loadmanager      = LoadManagerCreator().getManager();
    _transformmanager = TransformManagerCreator().getManager();
    _scenemanager     = SceneManagerCreator().getManager();
}
