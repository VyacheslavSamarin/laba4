#pragma once
#include "point.hpp"
#include <vector>
#include <iostream>
#include <memory>

template<Scalar T>
class Figure {
    public:
        Figure();
        Figure(const Figure<T>& other);
        Figure(const std::initializer_list<Point<T>> &lst);
        Figure<T>& operator=(const Figure<T>& other);
        Figure<T>& operator=(Figure<T>&& other) noexcept;
        bool operator==(const Figure<T>& other) const;
        virtual operator double() = 0;
        virtual Point<T> calc_geom_center() const = 0;
        virtual size_t count_point() const = 0;
    
    protected:
        std::vector<std::unique_ptr<Point<T>>> _points;
};