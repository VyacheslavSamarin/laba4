#include "Pentagon.hpp"

template<Scalar T>
Pentagon<T>::operator double() {
    T square = 0.0;
    size_t size = count_point();
    for (size_t i = 0; i < size - 1; ++i) {
        square += this->_points[i]->get_x() * this->_points[i + 1]->get_y();
        square -= this->_points[i]->get_y() * this->_points[i + 1]->get_x();
    }
    return 0.5 * square;
}

template<Scalar T>
Point<T> Pentagon<T>::calc_geom_center() const {
    T y_c = 0.0;
    T x_c = 0.0;
    size_t size = count_point();
    for (size_t i = 0; i < size; ++i) {
        x_c += this->_points[i]->get_x();
        y_c += this->_points[i]->get_y();
    }
    return Point<T>(x_c / size, y_c / size);
}

template<Scalar T>
bool Pentagon<T>::is_collinear(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) const {
    return (p1.get_x() * (p2.get_y() - p3.get_y()) +
            p2.get_x() * (p3.get_y() - p1.get_y()) +
            p3.get_x() * (p1.get_y() - p2.get_y()) == 0);
}

template<Scalar T>
std::istream& operator>>(std::istream& is, Pentagon<T>& t) {
    std::cout << "Введите 5 координат по порядку!" << std::endl;
    size_t size = t.count_point();
    T cur_x;
    T cur_y;
    for (size_t i = 0; i < size; ++i) {
        is >> cur_x >> cur_y;
        t._points.push_back(std::make_unique<Point<T>>(cur_x, cur_y));
    }
    for (size_t i = 0; i < size; ++i) {  
        if (t.is_collinear(*t._points[i % size], *t._points[(i + 1) % size], *t._points[(i + 2) % size])) {
            std::cerr << "It's not a pentagon, your coordinates are wrong" << std::endl;
            exit(1);
        }
    }
    return is;
}

template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T>& p) {
    size_t size = p.count_point();
    for (size_t i = 0; i < size; ++i) {
        os << "The " << i + 1 << " coordinate " << "x: " << p._points[i]->get_x() << " y: " << p._points[i]->get_y() << std::endl;
    }
    return os;
}

template<Scalar T>
size_t Pentagon<T>::count_point() const { return 5; }