//
// Created by Pavel Ivanov on 16.05.2022.
//

#include "TextFileModelLoader.hpp"
#include "exceptions/loader/LoaderException.hpp"

TextFileModelLoader::TextFileModelLoader(std::string &name)
{
    _file = std::make_shared<std::ifstream>();
    _filename = name;
}

void TextFileModelLoader::open()
{
    _file->open(_filename);

    if (!_file)
    {
        throw NoFileException(__FILE__, __LINE__);
    }
}

void TextFileModelLoader::close()
{
    if (!_file)
    {
        throw NoFileException(__FILE__, __LINE__);
    }

    _file->close();
}

std::shared_ptr<Object> TextFileModelLoader::load(std::shared_ptr<BaseBuilder> builder)
{
    open();

    std::shared_ptr<BaseModelBuilder> _builder = std::dynamic_pointer_cast<BaseModelBuilder>(builder);
    _builder->build();

    int points_count = 0;
    *_file >> points_count;

    if (points_count < 1)
    {
        throw IncorrectInputException(__FILE__, __LINE__, "Too few points!");
    }

    for (int i = 0; i < points_count; i++)
    {
        double x = 0, y = 0, z = 0;
        *_file >> x >> y >> z;

        _builder->buildPoint(x, y, z);
    }

    int edges_count = 0;
    *_file >> edges_count;

    if (edges_count < 1)
    {
        throw IncorrectInputException(__FILE__, __LINE__, "Too few edges!");
    }

    for (int i = 0; i < edges_count; i++)
    {
        int id1 = 0, id2 = 0;
        *_file >> id1 >> id2;

        _builder->buildEdge(id1, id2);
    }

    double center_x = 0, center_y = 0, center_z = 0;
    *_file >> center_x >> center_y >> center_z;

    _builder->buildCenter(center_x, center_y, center_z);

    close();

    return _builder->get();
}

std::shared_ptr<BaseLoader> TextFileModelLoaderCreator::createLoader(std::string &name)
{
    return std::make_shared<TextFileModelLoader>(name);
}