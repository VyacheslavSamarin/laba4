#pragma once
#include <iostream>
#include <type_traits>
#include <math.h>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
    public:
        Point();
        Point(T x, T y);
        double distance(const Point<T>& other);
        bool operator==(const Point<T>& other) const;
        bool operator!=(const Point<T>& other) const;
        friend std::istream& operator>>(std::istream& is, Point<T>& p);
        friend std::ostream& operator<<(std::ostream& os, const Point<T>& p);
        T get_x() const;
        T get_y() const;

    private:
        T _x;
        T _y;
};