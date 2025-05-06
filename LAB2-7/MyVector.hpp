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

    void resize(size_t newCapacity);

public:
    MyVector();
    ~MyVector();

    void push_back(const T& value);
    void remove(size_t index);
    void clear();
    size_t getSize() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};

// Реализация шаблонных методов в заголовочном файле
template <typename T>
MyVector<T>::MyVector() : data(nullptr), capacity(0), size(0) {}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] data;
}

template <typename T>
void MyVector<T>::resize(size_t newCapacity) {
    T* newData = new T[newCapacity];
    std::copy(data, data + size, newData);
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template <typename T>
void MyVector<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template <typename T>
void MyVector<T>::clear() {
    size = 0;
}

template <typename T>
size_t MyVector<T>::getSize() const {
    return size;
}

template <typename T>
T& MyVector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& MyVector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

#endif // MYVECTOR_HPP