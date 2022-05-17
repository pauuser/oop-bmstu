cmake_minimum_required(VERSION 3.21)
project(src)

set(MANAGERS
        managers/SceneManager/SceneManager.cpp managers/SceneManager/SceneManager.hpp
        managers/BaseManager/BaseManager.hpp managers/BaseManager/BaseManager.cpp
        managers/TransformManager/TransformManager.cpp managers/TransformManager/TransformManager.hpp
        managers/DrawManager/DrawManager.cpp managers/DrawManager/DrawManager.hpp
        commands/model/move/MoveModel.cpp commands/model/move/MoveModel.hpp
        commands/model/transform/TransformModel.cpp commands/model/transform/TransformModel.hpp managers/LoadManager/LoadManager.cpp managers/LoadManager/LoadManager.hpp)

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
        commands/camera/remove/RemoveCamera.cpp commands/camera/remove/RemoveCamera.hpp
        commands/camera/set/SetCamera.cpp commands/camera/set/SetCamera.hpp
        commands/model/add/AddModel.cpp commands/model/add/AddModel.hpp
        commands/model/count/CountModel.cpp commands/model/count/CountModel.hpp
        commands/model/remove/RemoveModel.cpp commands/model/remove/RemoveModel.hpp
        commands/model/rotate/RotateModel.cpp commands/model/rotate/RotateModel.hpp
        commands/model/scale/ScaleModel.cpp commands/model/scale/ScaleModel.hpp commands/model/load/LoadModel.cpp commands/model/load/LoadModel.hpp commands/camera/load/LoadCamera.cpp commands/camera/load/LoadCamera.hpp)

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

set(LOADER
        loader/BaseLoader.hpp
        loader/CameraLoader/CameraLoader.hpp
        loader/ModelLoader/ModelLoader.hpp
        loader/CameraLoader/FileCameraLoader/FileCameraLoader.hpp
        loader/ModelLoader/FileModelLoader/FileModelLoader.hpp
        loader/CameraLoader/FileCameraLoader/TextFileCameraLoader/TextFileCameraLoader.cpp
        loader/CameraLoader/FileCameraLoader/TextFileCameraLoader/TextFileCameraLoader.hpp loader/ModelLoader/FileModelLoader/TextFileModelLoader/TextFileModelLoader.cpp loader/ModelLoader/FileModelLoader/TextFileModelLoader/TextFileModelLoader.hpp loader/Solution/LoaderSolution.cpp loader/Solution/LoaderSolution.hpp)

set (BUILDER
        builder/BaseBuilder.hpp builder/Model/BaseModelBuilder.hpp
        builder/Model/FrameModelBuilder/FrameModelBuilder.cpp builder/Model/FrameModelBuilder/FrameModelBuilder.hpp
        builder/Camera/BaseCameraBuilder.hpp builder/Camera/CameraBuilder/CameraBuilder.cpp builder/Camera/CameraBuilder/CameraBuilder.hpp builder/Solution/BuilderSolution.cpp builder/Solution/BuilderSolution.hpp)


set(DIRECTOR
        director/BaseLoadDirector.hpp
        director/CameraDirector/CameraDirector.cpp director/CameraDirector/CameraDirector.hpp
        director/ModelDirector/ModelDirector.cpp director/ModelDirector/ModelDirector.hpp)

set(CONFIGURATION
        configuration/BaseConfiguration.hpp
        configuration/TextConfiguration/TextConfiguration.cpp configuration/TextConfiguration/TextConfiguration.hpp
        configuration/Solution/ConfigurationSolution.cpp configuration/Solution/ConfigurationSolution.hpp)

set(EXCEPTION
        exceptions/BaseException.hpp exceptions/ui/UiException.hpp)

add_library(${PROJECT_NAME}
        ${MANAGERS}
        ${FACADE}
        ${COMMANDS}
        ${OBJECTS}
        ${VISITOR}
        ${SCENE}
        ${LOADER}
        ${BUILDER}
        ${DIRECTOR}
        ${CONFIGURATION}
        ${EXCEPTION})

target_include_directories(${PROJECT_NAME} PUBLIC ../src)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)