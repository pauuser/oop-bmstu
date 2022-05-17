//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_TEXTCONFIGURATION_HPP
#define LAB_03_TEXTCONFIGURATION_HPP

#include <string>
#include <fstream>
#include <iostream>

#include "configuration/BaseConfiguration.hpp"
#include "loader/Solution/LoaderSolution.hpp"
#include "loader/CameraLoader/FileCameraLoader/TextFileCameraLoader/TextFileCameraLoader.hpp"
#include "loader/ModelLoader/FileModelLoader/TextFileModelLoader/TextFileModelLoader.hpp"
#include "builder/Model/FrameModelBuilder/FrameModelBuilder.hpp"
#include "builder/Solution/BuilderSolution.hpp"

class TextConfiguration : public BaseConfiguration
{
public:
    TextConfiguration(std::string filename);
    ~TextConfiguration() override;

    void read_configuration() override;
    virtual void register_framework() override;

private:
    std::shared_ptr<std::ifstream> _file;
    std::string _filename;

    std::string _guilib;
    std::string _source;
    std::string _modeltype;
};


#endif//LAB_03_TEXTCONFIGURATION_HPP
