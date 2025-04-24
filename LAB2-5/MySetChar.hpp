#ifndef MYSETCHAR_HPP
#define MYSETCHAR_HPP

#include "MyVectorChar.hpp"
#include <iostream>

class MySetChar : public MyVector<char*> {
private:
    using MyVector<char*>::data;
    using MyVector<char*>::size;
    using MyVector<char*>::capacity;

    int binary_find(const char* element) const {
        int left = 0;
        int right = size - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cmp = strcmp(data[mid], element);
            if (cmp == 0) return mid;
            if (cmp < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

public:
    using MyVector<char*>::MyVector;

    // Правило пяти
    MySetChar(const MySetChar& other) : MyVector<char*>(other) {}
    MySetChar& operator=(const MySetChar& other) {
        if (this != &other) {
            MyVector<char*>::operator=(other);
        }
        return *this;
    }

    bool is_element(const char* element) const {
        return binary_find(element) != -1;
    }

    void add_element(const char* element) {
        if (!is_element(element)) {
            MyVector<char*>::add_element(element);
            this->sort();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const MySetChar& set) {
        os << "{";
        for (size_t i = 0; i < set.size; ++i) {
            if (i != 0) os << ", ";
            os << "\"" << set.data[i] << "\"";
        }
        os << "}";
        return os;
    }

    MySetChar& operator+=(const MySetChar& other) {
        for (size_t i = 0; i < other.size; ++i) {
            this->add_element(other.data[i]);
        }
        return *this;
    }

    MySetChar& operator*=(const MySetChar& other) {
        MySetChar result;
        for (size_t i = 0; i < size; ++i) {
            if (other.is_element(data[i])) {
                result.add_element(data[i]);
            }
        }
        *this = result;
        return *this;
    }

    MySetChar& operator-=(const MySetChar& other) {
        for (size_t i = 0; i < other.size; ++i) {
            int index = this->find(other.data[i]);
            if (index != -1) {
                this->delete_element(index);
            }
        }
        return *this;
    }

    friend MySetChar operator+(MySetChar lhs, const MySetChar& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend MySetChar operator*(MySetChar lhs, const MySetChar& rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend MySetChar operator-(MySetChar lhs, const MySetChar& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend bool operator==(const MySetChar& lhs, const MySetChar& rhs) {
        if (lhs.size != rhs.size) return false;
        for (size_t i = 0; i < lhs.size; ++i) {
            if (strcmp(lhs.data[i], rhs.data[i]) != 0) return false;
        }
        return true;
    }
};

#endif // MYSETCHAR_HPP