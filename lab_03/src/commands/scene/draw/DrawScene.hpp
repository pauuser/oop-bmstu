//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_DRAWSCENE_HPP
#define LAB_03_DRAWSCENE_HPP

#include <memory>

#include "commands/scene/BaseSceneCommand.hpp"
#include "../../gui/drawer/BaseDrawer.hpp"

class DrawScene : public BaseSceneCommand
{
public:
    DrawScene() = delete;
    DrawScene(std::shared_ptr<BaseDrawer>& drawer);
    ~DrawScene() override = default;

    void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};


#endif//LAB_03_DRAWSCENE_HPP
