# CMakeList.txt: проект CMake для lab_02_1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

project(
    OOP_Lab_02
    DESCRIPTION "Lab 02 for BMSTU OOP Course, ICS7"
    LANGUAGES CXX
)
cmake_minimum_required(VERSION 3.5)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(
    _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING
)


#########
#  SRC  #
#########

set(SRC_DOMAIN src/)
set(SRC
        ${SRC_DOMAIN}/BaseMatrix.hpp
        ${SRC_DOMAIN}/ConstIterator.hpp
        ${SRC_DOMAIN}/Iterator.hpp
        
        ${SRC_DOMAIN}/BaseMatrix.hpp
        ${SRC_DOMAIN}/Matrix.hpp
        ${SRC_DOMAIN}/PrivateMatrix.hpp)

set(INC_DOMAIN inc/)
set(INC
        ${INC_DOMAIN}/BaseMatrix.h
        ${INC_DOMAIN}/ConstIterator.h
        ${INC_DOMAIN}/Iterator.h
        ${INC_DOMAIN}/Matrix.h
        ${INC_DOMAIN}/Exceptions.h)

##############
#  Dir conf  #
##############

include_directories(
        ${SRC_DOMAIN}
        ${INC_DOMAIN})

################
#  Executable  #
################

add_executable(lab_02
        main.cpp
        ${INC}
        ${SRC})

##########
#  Libs  #
##########

# target_link_libraries(
#         lab_02 ${GTEST_LIBRARIES} Threads::Threads)

# enable_testing()