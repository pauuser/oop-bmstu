//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "TextConfiguration.hpp"

TextConfiguration::TextConfiguration(std::string filename)
{
    this->_filename = filename;
    this->_file = std::make_shared<std::ifstream>();

    this->_file->open(this->_filename);

    if (!this->_file)
    {
        // TODO: add Exception
    }
}

TextConfiguration::~TextConfiguration()
{
    this->_file->close();
}

void TextConfiguration::read_configuration()
{
    if (!std::getline(*(this->_file), this->_guilib))
    {
        // TODO : add exception
    }

    if (!std::getline(*(this->_file), this->_source))
    {
        // TODO : add exception
    }

    if (!std::getline(*(this->_file), this->_modeltype))
    {
        // TODO : add exception
    }
}

TextConfigurationCreator::TextConfigurationCreator(std::string filename)
{
    _filename = filename;
}

void TextConfigurationCreator::_createConfiguration()
{
    _configuration = std::make_shared<TextConfiguration>(_filename);
}

std::shared_ptr<BaseConfiguration> TextConfigurationCreator::getConfiguration()
{
    if (_configuration == nullptr)
    {
        _createConfiguration();
    }

    return _configuration;
}

void TextConfiguration::register_framework()
{
    read_configuration();


    if (_source == "textfile")
    {
        LoaderSolution().registration("camera", std::make_shared<TextFileCameraLoaderCreator>());
        LoaderSolution().registration("model", std::make_shared<TextFileModelLoaderCreator>());
    }

    if (_modeltype == "frame")
    {
        BuilderSolution().registration("camera", std::make_shared<CameraBuilderCreator>());
        BuilderSolution().registration("model", std::make_shared<FrameModelBuilderCreator>());
    }
}
