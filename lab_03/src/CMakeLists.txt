cmake_minimum_required(VERSION 3.21)
project(src)

set(MANAGERS
        )

set(FACADE
        facade/Facade.cpp facade/Facade.hpp)

set(COMMANDS
        commands/BaseCommand.hpp)

set(OBJECTS
        objects/Object.hpp objects/Composite/Composite.cpp objects/Composite/Composite.hpp objects/Model/Model.hpp objects/Point/Point.cpp objects/Point/Point.hpp)

add_library(${PROJECT_NAME}
        ${MANAGERS}
        ${FACADE}
        ${COMMANDS}
        ${OBJECTS})

target_include_directories(${PROJECT_NAME} PUBLIC ../src)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)