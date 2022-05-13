cmake_minimum_required(VERSION 3.21)
project(src)

set(MANAGERS
        managers/SceneManager/SceneManager.cpp managers/SceneManager/SceneManager.hpp managers/BaseManager/BaseManager.hpp managers/BaseManager/BaseManager.cpp)

set(FACADE
        #facade/Facade.cpp facade/Facade.hpp
        )

set(COMMANDS
        #commands/BaseCommand.hpp)
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
        visitor/BaseVisitor.h visitor/DrawVisitor/DrawVisitor.cpp visitor/DrawVisitor/DrawVisitor.hpp)

set(SCENE
        scene/Scene.cpp scene/Scene.hpp)

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