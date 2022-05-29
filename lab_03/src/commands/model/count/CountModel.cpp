//
// Created by Pavel Ivanov on 14.05.2022.
//

#include "CountModel.hpp"
#include "managers/SceneManager/SceneManager.hpp"

CountModel::CountModel(std::shared_ptr<size_t> &cnt): _cnt(cnt) {
    _manager = SceneManagerCreator().getManager();
}

void CountModel::execute()
{
    *(this->_cnt) = _manager->getModelCount();
}