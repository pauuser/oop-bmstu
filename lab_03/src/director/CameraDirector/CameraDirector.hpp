//
// Created by Pavel Ivanov on 16.05.2022.
//

#ifndef LAB_03_CAMERADIRECTOR_HPP
#define LAB_03_CAMERADIRECTOR_HPP

#include "director/BaseLoadDirector.hpp"

class CameraDirector : BaseLoadDirector
{
public:
    CameraDirector() = default;
    ~CameraDirector() override = default;

    std::shared_ptr<Object> load() override;
    void setBuilder(std::shared_ptr<BaseBuilder> builder) override;
    void setLoader(std::shared_ptr<BaseLoader> loader) override;

private:
    std::shared_ptr<BaseLoader>  _loader  = nullptr;
    std::shared_ptr<BaseBuilder> _builder = nullptr;
};

class CameraDirectorCreator
{
public:
    CameraDirectorCreator() = default;
    ~CameraDirectorCreator() = default;

    std::shared_ptr<CameraDirector> getDirector();

private:
    std::shared_ptr<CameraDirector> _director = nullptr;
    void _createDirector();
};


#endif//LAB_03_CAMERADIRECTOR_HPP
