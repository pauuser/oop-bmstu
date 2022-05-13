//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_BASEVISITOR_H
#define LAB_03_BASEVISITOR_H

class Model;
class Scene;
class Camera;
class Composite;

class BaseVisitor
{
public:
    BaseVisitor() = default;
    virtual ~BaseVisitor() = default;

    virtual void visit(const Camera& camera) = 0;
    virtual void visit(const Model& model) = 0;
    virtual void visit(const Composite& composite) = 0;
    virtual void visit(const Scene& scene) = 0;
};

#endif//LAB_03_BASEVISITOR_H
