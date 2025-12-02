#ifndef VECTOR_IMPL_H
#define VECTOR_IMPL_H

#include <iostream>    
#include <algorithm> // copy
#include <cstddef> // size_t
#include <initializer_list> //п озволяет создавать векторы так Vector v{1, 2, 3};
#include <stdexcept> // at

class Vector {

    private:
        int* data_;
        size_t size_;
        size_t capacity_;
        
    public:
        // Конструктор 
        Vector();
        Vector(size_t count);
        Vector(std::initializer_list<int> init);  // из списка инициализации

        ~Vector();

        // Копирование 
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);

        // Методы доступа
        
        size_t Size() const;
        size_t Capacity() const;

        // Операторы доступа к элементам

        int& operator[](size_t index);
        const int& operator[](size_t index) const;

        // С проверкой At

        int& At(size_t index);
        const int& At(size_t index) const;


        // Операции
        void PushBack(int value);  
        void PopBack();            
        void Clear();               
        void Reserve(size_t new_capacity);  // v.Reserve(100) - зарезервировать память
        void Swap(Vector& other);

    private:
        void Reallocate(size_t new_capacity);
};

std::ostream& operator<<(std::ostream& os, const Vector& vec);


#endif