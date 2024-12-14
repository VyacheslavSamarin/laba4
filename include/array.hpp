#pragma once
#include "../include/figure.hpp"
#include <memory>

template<typename T>
class Array {
    public:
        Array();
        Array(size_t capacity);
        Array(const Array<T>& other);
        Array<T>& operator=(const Array<T>& other);
        Array<T>& operator=(Array<T>&& other) noexcept;
        void push_back(const T& value);
        void erase(size_t ind);
        T& operator[](size_t ind);
        double total_area();
        size_t get_size() const;
        size_t get_capacity() const;

    private:
        size_t _size;
        size_t _capacity;
        std::shared_ptr<T[]> _figures;
};