#include "Trapezoid.hpp"

template<Scalar T>
size_t Trapezoid<T>::count_point() const { return 4; }

template<Scalar T>
Trapezoid<T>::operator double() {
    double square = 0.0;
    size_t size = count_point();
    for (size_t i = 0; i < size - 1; ++i) {
        square += this->_points[i]->get_x() * this->_points[i + 1]->get_y();
        square -= this->_points[i]->get_y() * this->_points[i + 1]->get_x();
    }
    return 0.5 * square;
}

template<Scalar T>
bool Trapezoid<T>::is_trapezoid() const {
    double slope_ab = calculate_slope(*this->_points[0], *this->_points[1]);
    double slope_cd = calculate_slope(*this->_points[2], *this->_points[3]);

    double slope_bc = calculate_slope(*this->_points[1], *this->_points[2]);
    double slope_da = calculate_slope(*this->_points[3], *this->_points[0]);

    const double epsilon = 1e-6;

    return (std::abs(slope_ab - slope_cd) < epsilon || std::abs(slope_bc - slope_da) < epsilon);
}

template<Scalar T>
double Trapezoid<T>::calculate_slope(const Point<T>& p1, const Point<T>& p2) const {
    return (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x());
}

template<Scalar T>
Point<T> Trapezoid<T>::calc_geom_center() const {
    T y_c = 0.0;
    T x_c = 0.0;
    size_t size = count_point();
    for (size_t i = 0; i < size; ++i) {
        x_c += this->_points[i]->get_x();
        y_c += this->_points[i]->get_y();
    }
    return Point<T>(x_c / size, y_c / size);
}

template<Scalar U>
std::istream& operator>>(std::istream& is, Trapezoid<U>& t) {
    std::cout << "Введите 4 координаты по порядку!" << std::endl;
    size_t size = t.count_point();
    T cur_x;
    T cur_y;
    for (size_t i = 0; i < size; ++i) {
        is >> cur_x >> cur_y;
        t._points.push_back(std::make_unique<Point<T>>(cur_x, cur_y));
    }
    if (!t.is_trapezoid()) {
        std::cerr << "It's not a trapezoid, your coordinates are wrong" << std::endl;
        exit(1);
    }
    return is;
}

template<Scalar U>
std::ostream& operator<<(std::ostream& os, const Trapezoid<U>& t) {
    size_t size = t.count_point();
    for (size_t i = 0; i < size; ++i) {
        os << "The " << i + 1 << " coordinate " << "x: " << t._points[i]->get_x() << " y: " << t._points[i]->get_y() << std::endl;
    }
    return os;
}