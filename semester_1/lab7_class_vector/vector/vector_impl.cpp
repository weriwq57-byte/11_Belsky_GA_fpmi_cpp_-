#include "vector_impl.h"
#include <algorithm>  // для std::copy
#include <cstring>    // для std::memcpy (опционально)

// 1. Конструктор по умолчанию
Vector::Vector() : data_(nullptr), size_(0), capacity_(0) {}

// 2. Конструктор с размером
Vector::Vector(size_t count) : size_(count), capacity_(count) {
    if (count > 0) {
        data_ = new int[count];
        for (size_t i = 0; i < count; ++i) {
            data_[i] = 0;
        }
    } else {
        data_ = nullptr;
    }
}

// 3. Конструктор из initializer_list
Vector::Vector(std::initializer_list<int> init) 
    : size_(init.size()), capacity_(init.size()) {
    if (size_ > 0) {
        data_ = new int[size_];
        size_t i = 0;
        for (int value : init) {
            data_[i++] = value;
        }
    } else {
        data_ = nullptr;
    }
}

// 4. Деструктор
Vector::~Vector() {
    delete[] data_;
}

// 5. Size и Capacity
size_t Vector::Size() const {
    return size_;
}

size_t Vector::Capacity() const {
    return capacity_;
}

// 6. Оператор [] (неконстантный)
int& Vector::operator[](size_t index) {
    return data_[index];
}

// 7. Оператор [] (константный)
const int& Vector::operator[](size_t index) const {
    return data_[index];
}

// 8. Метод At (неконстантный)
int& Vector::At(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

// 9. Метод At (константный)
const int& Vector::At(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}