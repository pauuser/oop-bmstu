//
// Created by Pavel Ivanov on 12.05.2022.
//

#include "Edge.hpp"

Edge::Edge(size_t id_first, size_t id_second)
{
    this->first  = id_first;
    this->second = id_second;
}

Edge::Edge(Edge &&edge) noexcept
{
    this->first  = edge.first;
    this->second = edge.second;

    edge.~Edge();
}

Edge& Edge::operator=(Edge &&edge) noexcept
{
    this->first  = edge.first;
    this->second = edge.second;

    edge.~Edge();

    return *this;
}

void Edge::setFirst(size_t id_first)
{
    this->first = id_first;
}

size_t Edge::getFirst() const
{
    return this->first;
}

void Edge::setSecond(size_t id_second)
{
    this->second = id_second;
}

size_t Edge::getSecond() const
{
    return this->second;
}

bool Edge::operator==(const Edge &edge) const
{
    bool res = (this->first  && edge.first ) &&
               (this->second && edge.second);

    return res;
}

bool Edge::operator!=(const Edge &edge) const
{
    bool res = (this->first  && edge.first ) &&
               (this->second && edge.second);

    return !res;
}
