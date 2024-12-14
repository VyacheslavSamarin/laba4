#include "point.hpp"

template<Scalar T>
Point<T>::Point(): _x(0), _y(0) {}

template<Scalar T>
Point<T>::Point(T x, T y): _x{x}, _y{y} {}

template<Scalar T>
double Point<T>::distance(const Point<T>& other) {
    T df_x = this->_x - other._x;
    T df_y = this->_y - other._y;
    return std::sqrt(df_x * df_x + df_y * df_y);
}

template<Scalar T>
bool Point<T>::operator==(const Point<T>& other) const {
    return (this->_x == other._x && this->_y == other._y);
}

template<Scalar T>
bool Point<T>::operator!=(const Point<T>& other) const {
    return !(*this == other);
}

template<Scalar T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    is >> p._x >> p._y;
    return is;
}

template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << " " << p._x << " " <<p._y << std::endl;
    return os;
}

template<Scalar T>