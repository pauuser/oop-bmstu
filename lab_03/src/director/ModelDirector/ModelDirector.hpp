//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_MODELDIRECTOR_HPP
#define LAB_03_MODELDIRECTOR_HPP

#include "director/BaseLoadDirector.hpp"
#include "loader/BaseLoader.hpp"
#include "builder/BaseBuilder.hpp"

class ModelDirector : BaseLoadDirector
{
public:
    ModelDirector() = default;
    ~ModelDirector() override = default;

    std::shared_ptr<Object> load() override;
    void setBuilder(std::shared_ptr<BaseBuilder> builder) override;
    void setLoader(std::shared_ptr<BaseLoader> loader) override;

private:
    std::shared_ptr<BaseLoader>  _loader  = nullptr;
    std::shared_ptr<BaseBuilder> _builder = nullptr;
};

class ModelDirectorCreator
{
public:
    ModelDirectorCreator() = default;
    ~ModelDirectorCreator() = default;

    std::shared_ptr<ModelDirector> getDirector();

private:
    std::shared_ptr<ModelDirector> _director = nullptr;
    void _createDirector();
};


#endif//LAB_03_MODELDIRECTOR_HPP
