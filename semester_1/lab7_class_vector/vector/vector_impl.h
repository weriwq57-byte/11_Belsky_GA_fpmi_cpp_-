#pragma once

#include <cstddef>       // size_t
#include <initializer_list>
#include <stdexcept>
#include <iostream>  // для std::ostream

class Vector {
private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    int* data_ = nullptr;
    
    void reallocate(size_t new_capacity);

public:

    Vector();
    Vector(size_t size);
    Vector(std::initializer_list<int> list);
    
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    
    ~Vector();
    
    void Swap(Vector& other);
    
    void PushBack(int value);
    void PopBack();
    void Clear();
    void Reserve(size_t new_capacity);
    
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    int& At(size_t index);
    const int& At(size_t index) const;
    
    size_t Size() const;
    size_t Capacity() const;
    
    friend bool operator==(const Vector& lhs, const Vector& rhs);
    friend bool operator!=(const Vector& lhs, const Vector& rhs);
};
std::ostream& operator<<(std::ostream& os, const Vector& v);
