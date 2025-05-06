#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>
#include "MyVector.cpp"

template <typename T>
class MySet : public MyVector<T> {
public:
    explicit MySet(const T &el = T()) : MyVector<T>(el) {}

    friend MySet<T> operator+(const MySet<T> &s1, const MySet<T> &s2) {
        MySet<T> s;
        for(int i = 0; i < s1.size; i++) {
            s.add_element(s1[i]);
        }
        for(int i = 0; i < s2.size; i++) {
            s.add_element(s2[i]);
        }
        return s;
    }

    friend MySet<T> operator-(const MySet<T> &s1, const MySet<T> &s2) {
        MySet<T> s;
        for(int i = 0; i < s1.size; i++) {
            if(s2.find(s1[i]) == -1) {
                s.add_element(s1[i]);
            }
        }
        return s;
    }

    friend MySet<T> operator*(const MySet<T> &s1, const MySet<T> &s2) {
        MySet<T> s;
        for(int i = 0; i < s1.size; i++) {
            if(s2.find(s1[i]) != -1) {
                s.add_element(s1[i]);
            }
        }
        return s;
    }

    bool operator==(const MySet<T> &s) const {
        if(this->size != s.size) return false;
        for(int i = 0; i < this->size; i++) {
            if(!(this->pdata[i] == s.pdata[i])) {
                return false;
            }
        }
        return true;
    }

    MySet<T> &operator+=(const MySet<T> &s) {
        *this = *this + s;
        return *this;
    }

    MySet<T> &operator-=(const MySet<T> &s) {
        *this = *this - s;
        return *this;
    }

    MySet<T> &operator*=(const MySet<T> &s) {
        *this = *this * s;
        return *this;
    }

    void add_element(const T &el) {
        if(this->find(el) == -1) {
            MyVector<T>::add_element(el);
            this->sort();
        }
    }

    void delete_element(const T &el) {
        int idx = this->find(el);
        if(idx == -1) return;
        MyVector<T>::delete_element(idx);
    }

    bool is_element(const T &el) const {
        return this->find(el) != -1;
    }
};

// Специализация для char*
template <>
class MySet<char*> : public MyVector<char*> {
public:
    explicit MySet(const char *el = nullptr) : MyVector<char*>(el) {}

    friend MySet<char*> operator+(const MySet<char*> &s1, const MySet<char*> &s2) {
        MySet<char*> s;
        for(int i = 0; i < s1.size; i++) {
            s.add_element(s1[i]);
        }
        for(int i = 0; i < s2.size; i++) {
            s.add_element(s2[i]);
        }
        return s;
    }

    friend MySet<char*> operator-(const MySet<char*> &s1, const MySet<char*> &s2) {
        MySet<char*> s;
        for(int i = 0; i < s1.size; i++) {
            if(s2.find(s1[i]) == -1) {
                s.add_element(s1[i]);
            }
        }
        return s;
    }

    friend MySet<char*> operator*(const MySet<char*> &s1, const MySet<char*> &s2) {
        MySet<char*> s;
        for(int i = 0; i < s1.size; i++) {
            if(s2.find(s1[i]) != -1) {
                s.add_element(s1[i]);
            }
        }
        for(int i = 0; i < s2.size; i++) {
            if(s1.find(s2[i]) != -1) {
                s.add_element(s2[i]);
            }
        }
        return s;
    }

    bool operator==(const MySet<char*> &s) const {
        if(this->size != s.size) return false;
        for(int i = 0; i < this->size; i++) {
            if(std::strcmp(this->pdata[i], s.pdata[i]) != 0) {
                return false;
            }
        }
        return true;
    }

    MySet<char*> &operator+=(const MySet<char*> &s) {
        *this = *this + s;
        return *this;
    }

    MySet<char*> &operator-=(const MySet<char*> &s) {
        *this = *this - s;
        return *this;
    }

    MySet<char*> &operator*=(const MySet<char*> &s) {
        *this = *this * s;
        return *this;
    }

    void add_element(const char *el) {
        if(this->find(el) == -1) {
            MyVector<char*>::add_element(el);
            this->sort();
        }
    }

    void delete_element(const char *el) {
        int idx = this->find(el);
        if(idx == -1) return;
        MyVector<char*>::delete_element(idx);
    }

    bool is_element(const char *el) const {
        return this->find(el) != -1;
    }
};

#endif //INHERITANCE_MYSET_H