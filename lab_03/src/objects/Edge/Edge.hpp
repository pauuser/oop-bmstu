//
// Created by Pavel Ivanov on 12.05.2022.
//

#ifndef LAB_03_EDGE_HPP
#define LAB_03_EDGE_HPP

#include <memory>

class Edge
{
public:
    Edge() = default;
    Edge(size_t id_first, size_t id_second);
    ~Edge() = default;

    Edge(const Edge& edge) = default;
    Edge& operator=(const Edge &edge) = default;

    Edge(Edge&& edge) noexcept;
    Edge& operator=(Edge&& edge) noexcept;

    void   setFirst(size_t id_first);
    size_t getFirst() const;

    void   setSecond(size_t id_second);
    size_t getSecond() const;

    bool operator==(const Edge& edge) const;
    bool operator!=(const Edge& edge) const;

private:
    size_t  first = 0;
    size_t second = 0;
};


#endif//LAB_03_EDGE_HPP
