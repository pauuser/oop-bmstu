//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_COMPOSITE_HPP
#define LAB_03_COMPOSITE_HPP

#include <vector>

#include "../Object.hpp"
#include "visitor/BaseVisitor.h"

class Composite : public Object
{
public:
    Composite() = default;
    explicit Composite(const std::shared_ptr<Object>& obj);
    explicit Composite(const std::vector<std::shared_ptr<Object>>& vec);

    bool add(const std::shared_ptr<Object> &obj) override;
    bool remove(const Iterator &it) override;

    [[nodiscard]] bool isComposite() const override;
    [[nodiscard]] bool isVisible() const override;

    Iterator begin() override;
    Iterator end()   override;

    [[nodiscard]] ConstIterator begin()  const override;
    [[nodiscard]] ConstIterator end()    const override;

    [[nodiscard]] ConstIterator cbegin() const override;
    [[nodiscard]] ConstIterator cend()   const override;

    void accept(std::shared_ptr<BaseVisitor> visitor) override;
    void transform(const Point& move_params, const Point& scale_params, const Point& rotate_params) override;

private:
    std::vector<std::shared_ptr<Object>> _objects;
};


#endif//LAB_03_COMPOSITE_HPP
