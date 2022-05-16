//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_LOADMANAGER_HPP
#define LAB_03_LOADMANAGER_HPP

#include "managers/BaseManager/BaseManager.hpp"

class LoadManager : public BaseManager
{
public:
    LoadManager() = default;

    LoadManager(const LoadManager& manager) = delete;
    LoadManager& operator=(const LoadManager& manager) = delete;

    ~LoadManager() override = default;

private:

};


#endif//LAB_03_LOADMANAGER_HPP
