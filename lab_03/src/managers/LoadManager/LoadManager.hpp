//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_LOADMANAGER_HPP
#define LAB_03_LOADMANAGER_HPP

#include <memory>

#include "managers/BaseManager/BaseManager.hpp"
#include "director/BaseLoadDirector.hpp"
#include "objects/Object.hpp"
#include "director/BaseLoadDirector.hpp"

class LoadManager : public BaseManager
{
public:
    LoadManager() = default;

    LoadManager(const LoadManager& manager) = delete;
    LoadManager& operator=(const LoadManager& manager) = delete;

    ~LoadManager() override = default;

    void load();
    void setDirector(std::shared_ptr<BaseLoadDirector> director);

private:
    std::shared_ptr<BaseLoadDirector> _director = nullptr;
};

class LoadManagerCreator
{
public:
    std::shared_ptr<LoadManager> getManager(std::shared_ptr<BaseLoadDirector> director);

private:
    void _createManager();
    std::shared_ptr<LoadManager> _manager = nullptr;
};


#endif//LAB_03_LOADMANAGER_HPP
