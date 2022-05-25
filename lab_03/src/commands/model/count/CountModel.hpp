//
// Created by Pavel Ivanov on 14.05.2022.
//

#ifndef LAB_03_COUNTMODEL_HPP
#define LAB_03_COUNTMODEL_HPP

#include <memory>

#include "commands/model/BaseModelCommand.hpp"

class CountModel : public BaseModelCommand
{
public:
    CountModel() = delete;
    explicit CountModel(std::shared_ptr<size_t>& cnt);
    ~CountModel() override = default;

    void execute() override;

private:
    std::shared_ptr<size_t> _cnt;
};


#endif//LAB_03_COUNTMODEL_HPP
