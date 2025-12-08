#pragma once

#include <initializer_list>
#include <iostream>
#include <cstddef> // size_t
#include <stdexcept> // для исключения std::out_of_range в At()
#include <algorithm>

class Vector {
    private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    int* data_ = nullptr;
    void reallocate (size_t new_capacity) {
        if (new_capacity <= capacity_) {
            return;
        }

        int* new_data = new int[new_capacity];

        for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    public:
    Vector() {
        std::cout << "Default constructor\n";
    }

    Vector(size_t size) : size_(size), capacity_(size), data_(new int[size]) {
        std::cout << "size constructor\n";
        for (size_t i = 0; i < size_; i++) {
            data_[i] = 0;
        } 
    }

    Vector(std::initializer_list<int> list) 
        : size_(list.size()), capacity_(list.size()), data_(new int[list.size()]) {
            std::cout << "Initializer list constructor\n";
            size_t i = 0;
            for (int element : list) {
                data_[i] = element;
                ++i;
            }
    }

    Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_), data_(new int[other.capacity_]) {
        std::cout << "Copy constructor\n";
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    Vector& operator=(const Vector& other) {
        std::cout << "copy assignment operator\n";
         if (this == &other) {
            return *this;
        }
        
        Vector copy(other);
        Swap(copy);
        
        return *this;  
    }

    ~Vector() {
        std::cout << "destructor\n";
        delete[] data_;
    }
    
    void Swap(Vector& other) {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(data_, other.data_);
    }

    void PushBack(int value) {
        if(size_ == capacity_) {
            size_t new_capacity = (capacity_==0) ? 1 : capacity_ * 2;
            reallocate(new_capacity);
        }
        data_[size_] = value;
        size_++;
    }

    void PopBack() {
        if(size_ > 0) {
            --size_;
        }
    }

    void Clear() {
        size_ = 0;
    }

    void Reserve(size_t new_capacity) {
        if(new_capacity > capacity_) {
            reallocate(new_capacity);
        }
    }

    int& operator[](size_t index) {
        return data_[index];
    }
    
    const int& operator[](size_t index) const{
        return data_[index];
    }

    int& At(size_t index) {
        if(index >= size_) {
            throw std::out_of_range("index out of range\n");
        }
        return data_[index];
    }

    const int& At(size_t index) const {
        if(index >= size_) {
            throw std::out_of_range("index out of range\n");
        }
        return data_[index];
    }

    size_t Size() const {
        return size_;
    }

    size_t Capacity() const {
        return capacity_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& vec);
};

std::ostream& operator<<(std::ostream& out, const Vector& vec) {
    out << "[";
    for (size_t i = 0; i < vec.Size(); ++i) {
        out << vec[i];
        if (i < vec.Size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}