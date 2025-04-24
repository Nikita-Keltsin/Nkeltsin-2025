#ifndef MYSET_HPP
#define MYSET_HPP

#include "MyVector.hpp"
#include <iostream>

template <typename T>
class MySet : public MyVector<T> {
private:
    using MyVector<T>::data;
    using MyVector<T>::size;
    using MyVector<T>::capacity;

    int binary_find(const T& element) const {
        int left = 0;
        int right = size - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid] == element) return mid;
            if (data[mid] < element) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

public:
    using MyVector<T>::MyVector;

    // Правило пяти
    MySet(const MySet& other) : MyVector<T>(other) {}
    MySet& operator=(const MySet& other) {
        if (this != &other) {
            MyVector<T>::operator=(other);
        }
        return *this;
    }

    bool is_element(const T& element) const {
        return binary_find(element) != -1;
    }

    void add_element(const T& element) {
        if (!is_element(element)) {
            MyVector<T>::add_element(element);
            this->sort();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const MySet<T>& set) {
        os << "{";
        for (size_t i = 0; i < set.size; ++i) {
            if (i != 0) os << ", ";
            os << set.data[i];
        }
        os << "}";
        return os;
    }

    MySet& operator+=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            this->add_element(other.data[i]);
        }
        return *this;
    }

    MySet& operator*=(const MySet& other) {
        MySet<T> result;
        for (size_t i = 0; i < size; ++i) {
            if (other.is_element(data[i])) {
                result.add_element(data[i]);
            }
        }
        *this = result;
        return *this;
    }

    MySet& operator-=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            int index = this->find(other.data[i]);
            if (index != -1) {
                this->delete_element(index);
            }
        }
        return *this;
    }

    friend MySet operator+(MySet lhs, const MySet& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend MySet operator*(MySet lhs, const MySet& rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend MySet operator-(MySet lhs, const MySet& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend bool operator==(const MySet& lhs, const MySet& rhs) {
        if (lhs.size != rhs.size) return false;
        for (size_t i = 0; i < lhs.size; ++i) {
            if (lhs.data[i] != rhs.data[i]) return false;
        }
        return true;
    }
};

#endif // MYSET_HPP