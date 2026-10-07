#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void _resize_capacity(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    Vector() : _data(nullptr), _size(0), _capacity(0) {}

    Vector(size_t initial_size) : _data(nullptr), _size(initial_size), _capacity(initial_size) {
        if (_capacity > 0) {
            _data = new T[_capacity]();
        }
    }

    ~Vector() {
        delete[] _data;
    }

    Vector(const Vector& other) : _data(nullptr), _size(other._size), _capacity(other._capacity) {
        if (_capacity > 0) {
            _data = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            if (_capacity > 0) {
                _data = new T[_capacity];
                for (size_t i = 0; i < _size; ++i) {
                    _data[i] = other._data[i];
                }
            } else {
                _data = nullptr;
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        if (_size == _capacity) {
            size_t new_cap = (_capacity == 0) ? 1 : _capacity * 2;
            _resize_capacity(new_cap);
        }
        _data[_size++] = value;
    }

    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    T& operator[](size_t index) {
        return _data[index];
    }

    const T& operator[](size_t index) const {
        return _data[index];
    }

    T& at(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    const T& at(size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    T& front() {
        return _data[0];
    }

    const T& front() const {
        return _data[0];
    }

    T& back() {
        return _data[_size - 1];
    }

    const T& back() const {
        return _data[_size - 1];
    }

    size_t size() const {
        return _size;
    }

    size_t capacity() const {
        return _capacity;
    }

    bool empty() const {
        return _size == 0;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > _capacity) {
            _resize_capacity(new_capacity);
        }
    }

    void clear() {
        _size = 0;
    }

    T* begin() {
        return _data;
    }

    const T* begin() const {
        return _data;
    }

    T* end() {
        return _data + _size;
    }

    const T* end() const {
        return _data + _size;
    }
};

#endif // VECTOR_H