#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
class MyVector {
protected:
    size_t capacity;
    size_t size;
    T* data;

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    MyVector(size_t initial_capacity = 2) 
        : capacity(initial_capacity), size(0), data(new T[initial_capacity]) {}

    ~MyVector() {
        delete[] data;
    }

    void add_element(const T& element) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[size++] = element;
    }

    void delete_element(size_t index) {
        if (index >= size) return;
        
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;

        if (size <= capacity / 4 && capacity > 2) {
            resize(capacity / 2);
        }
    }

    int find(const T& element) const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == element) return i;
        }
        return -1;
    }

    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }

    void sort() {
        std::sort(data, data + size);
    }
};

#endif // MYVECTOR_HPP