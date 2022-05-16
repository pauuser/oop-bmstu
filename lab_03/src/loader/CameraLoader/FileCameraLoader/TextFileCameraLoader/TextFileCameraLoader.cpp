//
// Created by Pavel Ivanov on 15.05.2022.
//

#include "TextFileCameraLoader.hpp"

TextFileCameraLoader::TextFileCameraLoader()
{
    this->_file = std::make_shared<std::ifstream>();
}

void TextFileCameraLoader::open(std::string &name)
{
    // TODO: add exception if (!_file)

    _file->open(name);

    if (!_file)
    {
        // TODO: add Exception
    }
}

void TextFileCameraLoader::close()
{
    if (!_file)
    {
        // TODO add exception
    }

    _file->close();
}

std::shared_ptr<Object> TextFileCameraLoader::load(std::shared_ptr<BaseBuilder> builder)
{
    std::shared_ptr<CameraBuilder> _builder = std::dynamic_pointer_cast<CameraBuilder>(builder);
    _builder->build();

    double x = 0, y = 0, z = 0;

    *_file >> x >> y >> z;
    _builder->buildPosition(x, y, z);

    *_file >> x >> y >> z;
    _builder->buildAngle(x, y, z);

    return _builder->get();
}

std::shared_ptr<BaseLoader> TextFileCameraLoaderCreator::createLoader()
{
    return std::make_shared<TextFileCameraLoader>();
}