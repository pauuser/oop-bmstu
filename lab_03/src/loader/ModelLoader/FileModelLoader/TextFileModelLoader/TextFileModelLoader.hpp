//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_TEXTFILEMODELLOADER_HPP
#define LAB_03_TEXTFILEMODELLOADER_HPP

#include <fstream>

#include "loader/ModelLoader/FileModelLoader/FileModelLoader.hpp"
#include "builder/Model/FrameModelBuilder/FrameModelBuilder.hpp"

class TextFileModelLoader : public FileModelLoader
{
public:
    TextFileModelLoader(std::string &name);
    ~TextFileModelLoader() override = default;

    std::shared_ptr<Object> load(std::shared_ptr<BaseBuilder> builder) override;
    void open() override;
    void close() override;

private:
    std::shared_ptr<std::ifstream> _file;
    std::string _filename;
};

class TextFileModelLoaderCreator : public LoaderCreator
{
public:
    TextFileModelLoaderCreator() = default;
    ~TextFileModelLoaderCreator() = default;

    std::shared_ptr<BaseLoader> createLoader(std::string &name) override;
};


#endif//LAB_03_TEXTFILEMODELLOADER_HPP
