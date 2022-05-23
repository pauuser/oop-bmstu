//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "CountCamera.hpp"
#include "managers/SceneManager/SceneManager.hpp"

CountCamera::CountCamera(std::shared_ptr<size_t> &size): _count(size) {}

void CountCamera::execute()
{
    *(this->_count) = SceneManagerCreator().getManager()->getCameraCount();
}