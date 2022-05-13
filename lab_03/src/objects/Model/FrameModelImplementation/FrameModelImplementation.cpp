//
// Created by Pavel Ivanov on 13.05.2022.
//

#include "FrameModelImplementation.hpp"

FrameModelImplementation::FrameModelImplementation(const std::vector<Point> &points, const std::vector<Edge> &edges, const Point &center) :
                                                   _points(points), _edges(edges), _center(center) {}

void FrameModelImplementation::addPoint(const Point &point)
{
    this->_points.push_back(point);
}

void FrameModelImplementation::addEdge(const Edge &edge)
{
    this->_edges.push_back(edge);
}

void FrameModelImplementation::setCenter(const Point& center)
{
    this->_center = center;
}

const Point& FrameModelImplementation::getCenter()
{
    return this->_center;
}

const std::vector<Point> &FrameModelImplementation::_getPoints()
{
    return this->_points;
}

const std::vector<Edge> &FrameModelImplementation::_getEdges()
{
    return this->_edges;
}

void FrameModelImplementation::_move(const Point &move_params)
{
    for (Point &point: _points)
    {
        point.move(move_params.getX(), move_params.getY(), move_params.getZ());
    }

    this->_center.move(move_params.getX(), move_params.getY(), move_params.getZ());
}

void FrameModelImplementation::_scale(const Point &scale_params)
{
    for (Point &point: _points)
    {
        point.scale(scale_params.getX(), scale_params.getY(), scale_params.getZ());
    }
}

void FrameModelImplementation::_rotate(const Point &rotate_params)
{
    for (Point &point: _points)
    {
        point.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
    }
}

void FrameModelImplementation::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params)
{
    this->_move(move_params); // Moving object + center

    this->_move(-(this->_center));

    this->_scale(scale_params);
    this->_rotate(rotate_params);

    this->_move((this->_center));
}

