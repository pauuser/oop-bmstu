//
// Created by Pavel Ivanov on 15.05.2022.
//

#ifndef LAB_03_TEXTFILECAMERALOADER_HPP
#define LAB_03_TEXTFILECAMERALOADER_HPP

#include <fstream>

#include "loader/CameraLoader/FileCameraLoader/FileCameraLoader.hpp"
#include "builder/Camera/CameraBuilder/CameraBuilder.hpp"

class TextFileCameraLoader : public FileCameraLoader
{
public:
    TextFileCameraLoader();
    ~TextFileCameraLoader() override = default;

    std::shared_ptr<Object> load(std::shared_ptr<BaseBuilder> builder) override;
    void open(std::string &name) override;
    void close() override;

private:
    std::shared_ptr<std::ifstream> _file;
};

class TextFileCameraLoaderCreator : public LoaderCreator
{
public:
    TextFileCameraLoaderCreator() = default;
    ~TextFileCameraLoaderCreator() = default;

    std::shared_ptr<BaseLoader> createLoader() override;
};


#endif//LAB_03_TEXTFILECAMERALOADER_HPP
