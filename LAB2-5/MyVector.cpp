#include "MyVector.hpp"
MyVector::MyVector(const char *el, int maxsz) {
    size = 0;
    maxsize = maxsz;
    pdata = new char*[maxsize];
    if(el!= nullptr){
        add_element(el);
    }
}

MyVector::~MyVector() {
    for(int i = 0; i < size; i++){
        delete[] pdata[i];
    }
    delete[] pdata;
}

void MyVector::add_element(const char *el) {
    if(size == maxsize){
        resize();
    }
    pdata[size] = new char[MAX_LENGTH];
    std::strcpy(pdata[size], el);
    size++;
}

void MyVector::resize() {
    maxsize*=2;
    char **newdata = new char*[maxsize];
    for(int i = 0; i < size; i ++){
        newdata[i] = pdata[i];
    }
    delete[] pdata;
    pdata = newdata;
}

MyVector::MyVector(MyVector const &v) {
    size = v.size;
    maxsize = v.maxsize;
    pdata = new char*[maxsize];
    for(int i = 0; i < size; i ++){
        pdata[i] = new char[MAX_LENGTH];
        std::strcpy(pdata[i], v.pdata[i]);
    }
}

bool MyVector::delete_element(int idx) {
    if(idx>=size){
        return false;
    }
    for(int i = idx; i < size-1; i ++){
        std::strcpy(pdata[i], pdata[i+1]);
    }
    delete[] pdata[size];
    size--;
    return true;
}

char *MyVector::operator[](int i) const {
    return pdata[i];
}

int MyVector::find(const char *el) const{
    for(int i = 0; i < size; i++){
        if(std::strcmp(el, pdata[i]) == 0){
            return i;
        }
    }
    return -1;
}

MyVector &MyVector::operator=(MyVector const &v) {
    if(this == &v) return *this;
    size = v.size;
    maxsize = v.maxsize;
    pdata = new char*[maxsize];
    for(int i = 0; i < size; i ++){
        pdata[i] = new char[MAX_LENGTH];
        std::strcpy(pdata[i], v.pdata[i]);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out,MyVector const &v) {
    for(int i = 0; i < v.size; i++){
        out << v.pdata[i] << ' ';
    }
    return out;
}

void MyVector::sort() {
    if(size==0) return;
    char max[MAX_LENGTH];
    for(int i = size; i > 0; i--){
        int maxi = 0;
        std::strncpy(max, pdata[0], MAX_LENGTH);
        for(int j = 0; j < i; j++){
            if(strcmp(pdata[j],max)>0){
                std::strcpy(max, pdata[j]);
                maxi = j;
            }
        }
        std::strcpy(pdata[maxi], pdata[i-1]);
        std::strcpy(pdata[i-1], max);
    }
}
