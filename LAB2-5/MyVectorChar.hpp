#ifndef MYVECTORCHAR_HPP
#define MYVECTORCHAR_HPP

#include <cstring>
#include <algorithm>
#include <stdexcept>
#include "MyVector.hpp"

template <>
class MyVector<char*> {
protected:
    size_t capacity;
    size_t size;
    char** data;

    void resize(size_t new_capacity) {
        char** new_data = new char*[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = new char[strlen(data[i]) + 1];
            strcpy(new_data[i], data[i]);
            delete[] data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    MyVector(size_t initial_capacity = 2) 
        : capacity(initial_capacity), size(0), data(new char*[initial_capacity]) {}

    ~MyVector() {
        for (size_t i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void add_element(const char* element) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[size] = new char[strlen(element) + 1];
        strcpy(data[size++], element);
    }

    void delete_element(size_t index) {
        if (index >= size) return;
        
        delete[] data[index];
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;

        if (size <= capacity / 4 && capacity > 2) {
            resize(capacity / 2);
        }
    }

    int find(const char* element) const {
        for (size_t i = 0; i < size; ++i) {
            if (strcmp(data[i], element) == 0) return i;
        }
        return -1;
    }

    char* operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const char* operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }

    void sort() {
        std::sort(data, data + size, [](const char* a, const char* b) {
            return strcmp(a, b) < 0;
        });
    }
};

#endif // MYVECTORCHAR_HPP