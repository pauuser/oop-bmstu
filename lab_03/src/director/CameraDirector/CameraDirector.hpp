//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_CAMERADIRECTOR_HPP
#define LAB_03_CAMERADIRECTOR_HPP

#include <string>

#include "director/BaseLoadDirector.hpp"
#include "loader/Solution/LoaderSolution.hpp"
#include "builder/Solution/BuilderSolution.hpp"

class CameraDirector : BaseLoadDirector
{
public:
    explicit CameraDirector(std::string name);
    ~CameraDirector() override = default;

    std::shared_ptr<Object> load() override;
    void setBuilder(std::shared_ptr<BaseBuilder> builder) override;
    void setLoader(std::shared_ptr<BaseLoader> loader) override;
    void setName(std::string name) override;

private:
    std::string _name{};

    std::shared_ptr<BaseLoader>  _loader  = nullptr;
    std::shared_ptr<BaseBuilder> _builder = nullptr;
};

class CameraDirectorCreator
{
public:
    CameraDirectorCreator() = default;
    ~CameraDirectorCreator() = default;

    std::shared_ptr<CameraDirector> getDirector(std::string name);

private:
    std::shared_ptr<CameraDirector> _director = nullptr;
    void _createDirector(std::string name);
};


#endif//LAB_03_CAMERADIRECTOR_HPP
