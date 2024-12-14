#pragma once
#include "figure.hpp"
#include "cmath"

template<Scalar T>
class Trapezoid: public Figure<T> {
public:
    size_t count_point() const override;
    virtual operator double() override;
    bool is_trapezoid() const;
    double calculate_slope(const Point<T>& p1, const Point<T>& p2) const;
    virtual Point<T> calc_geom_center() const override;
    template<Scalar U>
    friend std::istream& operator>>(std::istream& is, Trapezoid<U>& t);
    template<Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid<U>& t);
};