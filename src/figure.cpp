#include "figure.hpp"

template<Scalar T>
Figure<T>::Figure() {
    _points = std::vector<std::unique_ptr<Point<T>>>();
}

template<Scalar T>
Figure<T>::Figure(const Figure<T>& other) {
    for (size_t i = 0; i < other.count_point(); ++i) {
        _points.push_back(std::make_unique<Point<T>>(*other._points[i]));
    }
}

template<Scalar T>
Figure<T>::Figure(const std::initializer_list<Point<T>> &lst) {
    _points.reserve(lst.size());
    for (const auto &t : lst) {
        _points.push_back(std::make_unique<Point<T>>(t));
    }
}

template<Scalar T>
Figure<T>& Figure<T>::operator=(const Figure<T>& other) {
    if (this == &other) {
        return *this;
    }
    this->_points.clear();
    for (size_t i = 0; i < other._points.size(); ++i) {
        _points.push_back(std::make_unique<Point<T>>(*other._points[i]));
    }
    return *this;
}

template<Scalar T>
Figure<T>& Figure<T>::operator=(Figure<T>&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    this->_points = std::move(other._points);
    other._points.clear();
    return *this;
}

template<Scalar T>
bool Figure<T>::operator==(const Figure<T>& other) const {
    if (this->_points.size() != other._points.size()) {
        return false;
    }
    for (size_t i = 0; i < other._points.size(); ++i) {
        if (*_points[i] != *other._points[i]) {
            return false;
        } 
    }
    return true;
}