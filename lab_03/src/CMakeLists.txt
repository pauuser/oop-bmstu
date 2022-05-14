cmake_minimum_required(VERSION 3.21)
project(src)

set(MANAGERS
        managers/SceneManager/SceneManager.cpp managers/SceneManager/SceneManager.hpp
        managers/BaseManager/BaseManager.hpp managers/BaseManager/BaseManager.cpp
        managers/TransformManager/TransformManager.cpp managers/TransformManager/TransformManager.hpp
        managers/DrawManager/DrawManager.cpp managers/DrawManager/DrawManager.hpp
        )

set(FACADE
        facade/Facade.cpp facade/Facade.hpp
        )

set(COMMANDS
        commands/BaseCommand.hpp
        commands/model/BaseModelCommand.hpp
        commands/scene/BaseSceneCommand.hpp
        commands/camera/BaseCameraCommand.hpp
        commands/camera/add/AddCamera.cpp commands/camera/add/AddCamera.hpp
        commands/camera/count/CountCamera.cpp commands/camera/count/CountCamera.hpp
        commands/camera/move/MoveCamera.cpp commands/camera/move/MoveCamera.hpp
        commands/scene/draw/DrawScene.cpp commands/scene/draw/DrawScene.hpp
        commands/camera/remove/RemoveCamera.cpp commands/camera/remove/RemoveCamera.h
        commands/camera/set/SetCamera.cpp commands/camera/set/SetCamera.hpp
        commands/model/add/AddModel.cpp commands/model/add/AddModel.hpp
        )

set(OBJECTS
        objects/Object.hpp
        objects/Composite/Composite.cpp objects/Composite/Composite.hpp
        objects/Model/Model.hpp
        objects/Point/Point.cpp objects/Point/Point.hpp
        objects/Edge/Edge.cpp objects/Edge/Edge.hpp
        objects/Model/FrameModel/FrameModel.cpp objects/Model/FrameModel/FrameModel.hpp
        objects/Model/FrameModelImplementation/FrameModelImplementation.cpp objects/Model/FrameModelImplementation/FrameModelImplementation.hpp
        objects/Camera/Camera.cpp objects/Camera/Camera.hpp)

set(VISITOR
        visitor/BaseVisitor.h
        visitor/DrawVisitor/DrawVisitor.cpp visitor/DrawVisitor/DrawVisitor.hpp)

set(SCENE
        scene/Scene.cpp scene/Scene.hpp
        )

add_library(${PROJECT_NAME}
        ${MANAGERS}
        ${FACADE}
        ${COMMANDS}
        ${OBJECTS}
        ${VISITOR}
        ${SCENE})

target_include_directories(${PROJECT_NAME} PUBLIC ../src)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)