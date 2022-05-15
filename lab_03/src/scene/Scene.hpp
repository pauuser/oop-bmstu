//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_SCENE_HPP
#define LAB_03_SCENE_HPP

#include <memory>

#include "../objects/Object.hpp"
#include "../objects/Composite/Composite.hpp"

class Scene
{
public:
    Scene();
    ~Scene() = default;

    void addObject(const std::shared_ptr<Object>& object);
    void removeObject(const Iterator& it);

    Iterator begin();
    Iterator end();

    [[nodiscard]] ConstIterator cbegin()  const;
    [[nodiscard]] ConstIterator cend()    const;

    [[nodiscard]] ConstIterator begin()   const;
    [[nodiscard]] ConstIterator end()     const;

    [[nodiscard]] size_t getModelCount()  const;
    [[nodiscard]] size_t getCameraCount() const;

private:
    std::shared_ptr<Composite> _objects;

    size_t _camera_count = 0;
    size_t _model_count  = 0;
};


#endif//LAB_03_SCENE_HPP
