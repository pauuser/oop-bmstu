//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_TRANSFORMMANAGER_HPP
#define LAB_03_TRANSFORMMANAGER_HPP

#include <memory>

#include "managers/BaseManager/BaseManager.hpp"
#include "objects/Object.hpp"


class TransformManager : public BaseManager
{
public:
    TransformManager() = default;

    TransformManager(const TransformManager& manager) = delete;
    TransformManager& operator=(const TransformManager& manager) = delete;

    ~TransformManager() override = default;

    void transformVisible(size_t scene_id, const Point& move_params, const Point& scale_params, const Point& rotate_params);
    void transformInvisible(size_t scene_id, const Point& move_params, const Point& scale_params, const Point& rotate_params);

};

class TransformManagerCreator
{
public:
    std::shared_ptr<TransformManager> getManager();

private:
    void _createManager();
    std::shared_ptr<TransformManager> _manager = nullptr;

};


#endif//LAB_03_TRANSFORMMANAGER_HPP
