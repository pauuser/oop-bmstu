//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_DRAWVISITOR_HPP
#define LAB_03_DRAWVISITOR_HPP

#include "../BaseVisitor.h"

class DrawVisitor : public BaseVisitor
{
public:
    void visit(const Camera& camera) override;
    void visit(const Model& model) override;
    void visit(const Composite& composite) override;
    void visit(const Scene& scene) override;

    // TODO: add projection and implementation

private:


};


#endif//LAB_03_DRAWVISITOR_HPP
