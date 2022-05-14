//
// Created by Pavel Ivanov on 13.05.2022.
//

#ifndef LAB_03_FRAMEMODELIMPLEMENTATION_HPP
#define LAB_03_FRAMEMODELIMPLEMENTATION_HPP

#include <memory>
#include <vector>

#include "../../Point/Point.hpp"
#include "../../Edge/Edge.hpp"
#include "visitor/DrawVisitor/DrawVisitor.hpp"

class FrameModelImplementation
{
public:
    FrameModelImplementation() = default;
    FrameModelImplementation(const std::vector<Point>& points, const std::vector<Edge>& edges, const Point& center = {});
    ~FrameModelImplementation() = default;

    void addPoint (const Point &point);
    void addEdge  (const Edge &edge);

    void setCenter(const Point& center);
    const Point& getCenter();

    virtual void transform(const Point& move_params, const Point& scale_params, const Point& rotate_params);

    friend void DrawVisitor::visit(const FrameModel &model);

protected:
    const std::vector<Point>& _getPoints();
    const std::vector<Edge>&  _getEdges();

private:
    std::vector<Point> _points;
    std::vector<Edge>  _edges;
    Point _center{};

    void _move  (const Point& move_params);
    void _scale (const Point& scale_params);
    void _rotate(const Point& rotate_params);
};


#endif//LAB_03_FRAMEMODELIMPLEMENTATION_HPP
