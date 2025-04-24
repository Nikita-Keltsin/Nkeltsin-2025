#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>
#include "MyVector.hpp"

class MySet : public MyVector {
public:
    explicit MySet(const char *el = nullptr) : MyVector(el) {};

    friend MySet operator+(MySet const &s1, MySet const &s2);

    friend MySet operator-(MySet const &s1, MySet const &s2);

    friend MySet operator*(MySet const &s1, MySet const &s2);

    bool operator==(MySet const &s);

    MySet &operator+=(MySet const &s);

    MySet &operator-=(MySet const &s);

    MySet &operator*=(MySet const &s);

    void add_element(const char *el);

    void delete_element(const char *el);

    bool is_element(const char *el);
};

#endif //INHERITANCE_MYSET_H
