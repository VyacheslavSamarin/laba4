#pragma once
#include "figure.hpp"
#include "cmath"

template<Scalar T>
class Pentagon: public Figure<T> {
public:
    virtual operator double() override;
    virtual Point<T> calc_geom_center() const override;
    bool is_collinear(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) const;
    friend std::istream& operator>>(std::istream& is, Pentagon<T>& t);
    friend std::ostream& operator<<(std::ostream& os, const Pentagon<T>& p);
    virtual size_t count_point() const override;
};