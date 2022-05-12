cmake_minimum_required(VERSION 3.21)
project(src)

set(MANAGERS
        )

add_library(${PROJECT_NAME}
        ${MANAGERS})

target_include_directories(${PROJECT_NAME} PUBLIC ../src)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)