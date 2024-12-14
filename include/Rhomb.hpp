#pragma once
#include "figure.hpp"
#include "cmath"
#define eps 1e-12

template<Scalar T>
class Rhomb: public Figure<T> {
    public:
        virtual operator double() override;
        virtual Point<T> calc_geom_center() const override;
        T side_calculation(T x1, T x2, T y1, T y2);
        friend std::istream& operator>>(std::istream& is, Rhomb<T>& r);
        friend std::ostream& operator<<(std::ostream& os, const Rhomb<T>& r);
        virtual size_t count_point() const override;
};