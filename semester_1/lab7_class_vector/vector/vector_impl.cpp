#include "vector_impl.h"
#include <algorithm>
#include <iostream>

Vector::Vector() = default;

Vector::Vector(size_t size) 
    : size_(size), capacity_(size), data_(new int[size]) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> list) 
    : size_(list.size()), capacity_(list.size()), data_(new int[list.size()]) {
    size_t i = 0;
    for (int item : list) {
        data_[i++] = item;
    }
}

Vector::Vector(const Vector& other) 
    : size_(other.size_), capacity_(other.capacity_), data_(new int[other.capacity_]) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) { 
        return *this;
    }
    
    Vector copy(other);  
    Swap(copy);        
    
    return *this;
}

Vector::~Vector() {
    delete[] data_;
}

void Vector::reallocate(size_t new_capacity) {
    if (new_capacity <= capacity_) {
        return; 
    }
    
    int* new_data = new int[new_capacity];  
    
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];  
    }
    
    delete[] data_;   
    data_ = new_data; 
    capacity_ = new_capacity; 
}

void Vector::Swap(Vector& other) {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(data_, other.data_);
}

void Vector::PushBack(int value) {
    if (size_ == capacity_) { 
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        reallocate(new_capacity);  
    }
    
    data_[size_] = value;  
    ++size_;               
}

void Vector::PopBack() {
    if (size_ > 0) {
        --size_;  
    }
}


void Vector::Clear() {
    size_ = 0;  
}

void Vector::Reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        reallocate(new_capacity); 
    }
}

int& Vector::operator[](size_t index) {
    return data_[index];  
}

const int& Vector::operator[](size_t index) const {
    return data_[index];  
}

int& Vector::At(size_t index) {
    if (index >= size_) {  
        throw std::out_of_range("Index out of range");  
    }
    return data_[index];
}

const int& Vector::At(size_t index) const {
    if (index >= size_) {  
        throw std::out_of_range("Index out of range");  
    }
    return data_[index];
}

size_t Vector::Size() const {
    return size_;
}

size_t Vector::Capacity() const {
    return capacity_;
}

bool operator==(const Vector& lhs, const Vector& rhs) {
    if (lhs.size_ != rhs.size_) {  
        return false;
    }
    
    for (size_t i = 0; i < lhs.size_; ++i) {
        if (lhs.data_[i] != rhs.data_[i]) { 
            return false;
        }
    }
    
    return true;  
}

bool operator!=(const Vector& lhs, const Vector& rhs) {
    return !(lhs == rhs); 
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (size_t i = 0; i < v.Size(); ++i) {
        os << v[i];
        if (i + 1 != v.Size()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
