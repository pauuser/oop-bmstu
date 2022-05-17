//
// Created by Pavel Ivanov on 15.05.2022.
//

#include "TextFileCameraLoader.hpp"
#include "exceptions/loader/LoaderException.hpp"

TextFileCameraLoader::TextFileCameraLoader(std::string &name)
{
    this->_file = std::make_shared<std::ifstream>();
    this->_filename = name;
}

void TextFileCameraLoader::open()
{
    _file->open(_filename);

    if (!_file)
    {
        throw NoFileException(__FILE__, __LINE__);
    }
}

void TextFileCameraLoader::close()
{
    if (!_file)
    {
        throw NoFileException(__FILE__, __LINE__);
    }

    _file->close();
}

std::shared_ptr<Object> TextFileCameraLoader::load(std::shared_ptr<BaseBuilder> builder)
{
    open();

    std::shared_ptr<BaseCameraBuilder> _builder = std::dynamic_pointer_cast<BaseCameraBuilder>(builder);
    _builder->build();

    double x = 0, y = 0, z = 0;

    *_file >> x >> y >> z;
    _builder->buildPosition(x, y, z);

    *_file >> x >> y >> z;
    _builder->buildAngle(x, y, z);

    close();

    return _builder->get();
}

std::shared_ptr<BaseLoader> TextFileCameraLoaderCreator::createLoader(std::string &name)
{
    return std::make_shared<TextFileCameraLoader>(name);
}