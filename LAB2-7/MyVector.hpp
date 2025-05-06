#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>
class MyVector {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        std::copy(data, data + size, newData);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    MyVector() : data(nullptr), capacity(0), size(0) {}
    ~MyVector() { delete[] data; }

    void push_back(const T& value) {
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    void remove(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    void clear() { size = 0; }
    size_t getSize() const { return size; }

    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }
};

#endif // MYVECTOR_HPP