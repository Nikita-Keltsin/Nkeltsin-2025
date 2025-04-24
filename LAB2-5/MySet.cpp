#include "MySet.hpp"
bool MySet::is_element(const char *el) {
    if(find(el)!=-1) return true;
    return false;
}

void MySet::delete_element(const char *el) {
    int idx = find(el);
    if(idx==-1) return;
    MyVector::delete_element(idx);
}

void MySet::add_element(const char *el) {
    if(find(el)==-1) MyVector::add_element(el);
    sort();
}

MySet operator+(MySet const &s1, MySet const &s2) {
    MySet s;
    for(int i = 0; i < s1.size; i++){
        s.add_element(s1[i]);
    }
    for(int i = 0; i < s2.size; i++){
        s.add_element(s2[i]);
    }
    return s;
}

MySet operator-(MySet const &s1, MySet const &s2) {
    MySet s;
    for(int i = 0; i < s1.size; i++){
        if(s2.find(s1[i]) == -1){
            s.add_element(s1[i]);
        }
    }
    return s;
}

MySet operator*(MySet const &s1, MySet const &s2) {
    MySet s;
    for(int i = 0; i < s1.size; i++){
        if(s2.find(s1[i]) != -1){
            s.add_element(s1[i]);
        }
    }
    for(int i = 0; i < s2.size; i++){
        if(s1.find(s2[i]) != -1){
            s.add_element(s2[i]);
        }
    }
    return s;
}

bool MySet::operator==(MySet const &s) {
    if(size!=s.size) return false;
    for(int i = 0; i < size; i++){
        if(std::strcmp(pdata[i],s.pdata[i])!=0){
            return false;
        }
    }
    return true;
}

MySet &MySet::operator+=(MySet const &s) {
    *this = *this + s;
    return *this;
}

MySet &MySet::operator-=(MySet const &s) {
    *this = *this - s;
    return *this;
}

MySet &MySet::operator*=(MySet const &s) {
    *this = *this * s;
    return *this;
}

