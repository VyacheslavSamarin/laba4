#include "array.hpp"

template<typename T>
Array<T>::Array(): _figures(nullptr), _size(0), _capacity(0) {}

template<typename T>
Array<T>::Array(size_t capacity): _size(capacity), _capacity(capacity) {
    _figures = std::shared_ptr<T[]>(new T[capacity]);
}

template<typename T>
Array<T>::Array(const Array<T>& other){
    _size = other._size;
    _capacity = other._capacity;
    _figures = std::shared_ptr<T[]>(new T[_capacity]);
    for(size_t i = 0; i < _size; ++i) {
        _figures[i] = other._figures[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other) {
        return *this;
    }
    _size = other._size;
    _capacity = other._capacity;
    _figures = std::shared_ptr<T[]>(new T[_capacity]);
    for(size_t i = 0; i < _size; ++i) {
        _figures[i] = other._figures[i];
    }
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
    if (this != &other) {
        _size = other._size;
        _capacity = other._capacity;
        _figures = std::move(other._figures);
        other._size = 0;
        other._capacity = 0;
        other._figures = nullptr;
    }
    return *this;
}

template<typename T>
void Array<T>::push_back(const T& value) {
    if (_size == _capacity) {
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        std::shared_ptr<T[]> new_figures (new T[_capacity]);
        for(size_t i = 0; i < _size; ++i) {
            new_figures[i] = std::move(this->_figures[i]);
        }
        _figures = std::move(new_figures);
    }
    _figures[_size++] = value;
}

template<typename T>
void Array<T>::erase(size_t ind) {
    if (ind < _size) {
        for (size_t i = ind; i < _size - 1; ++i) {
            _figures[i] = std::move(_figures[i+1]);
        }
        --_size;
    }
}

template<typename T>
T& Array<T>::operator[](size_t ind) {
    return _figures[ind];
}

template<typename T>
double Array<T>::total_area() {
    double area = 0;
    for (size_t i = 0; i < _size - 1; ++i) {
        area += double(*_figures[i]);
    }
    return area;
}

template<typename T>
size_t Array<T>::get_size() const {return _size;}

template<typename T>
size_t Array<T>::get_capacity() const {return _capacity;}