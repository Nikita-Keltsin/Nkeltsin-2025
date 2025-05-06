#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>
#include <cstring>
#include <algorithm>

const int MAX_SIZE = 4;
const int MAX_LENGTH = 256;

template <typename T>
class MyVector {
public:
    explicit MyVector(const T &el = T(), int maxsz = MAX_SIZE) {
        size = 0;
        maxsize = maxsz;
        pdata = new T[maxsize];
        if(el != T()) {
            add_element(el);
        }
    }

    MyVector(const MyVector<T> &v) {
        size = v.size;
        maxsize = v.maxsize;
        pdata = new T[maxsize];
        for(int i = 0; i < size; i++) {
            pdata[i] = v.pdata[i];
        }
    }

    virtual ~MyVector() {
        delete[] pdata;
    }

    void add_element(const T &el) {
        if(size == maxsize) {
            resize();
        }
        pdata[size] = el;
        size++;
    }

    bool delete_element(int idx) {
        if(idx >= size) {
            return false;
        }
        for(int i = idx; i < size-1; i++) {
            pdata[i] = pdata[i+1];
        }
        size--;
        return true;
    }

    const T& operator[](int i) const {
        return pdata[i];
    }

    T& operator[](int i) {
        return pdata[i];
    }

    void sort() {
        std::sort(pdata, pdata + size);
    }

    [[nodiscard]] int Size() const { return size; }
    [[nodiscard]] int Maxsize() const { return maxsize; }

    int find(const T &el) const {
        for(int i = 0; i < size; i++) {
            if(pdata[i] == el) {
                return i;
            }
        }
        return -1;
    }

    MyVector<T> &operator=(const MyVector<T> &v) {
        if(this == &v) return *this;
        delete[] pdata;
        size = v.size;
        maxsize = v.maxsize;
        pdata = new T[maxsize];
        for(int i = 0; i < size; i++) {
            pdata[i] = v.pdata[i];
        }
        return *this;
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const MyVector<U> &v) {
        for(int i = 0; i < v.size; i++) {
            out << v.pdata[i] << ' ';
        }
        return out;
    }

protected:
    int maxsize;
    int size;
    T *pdata;

private:
    void resize() {
        maxsize *= 2;
        T *newdata = new T[maxsize];
        for(int i = 0; i < size; i++) {
            newdata[i] = pdata[i];
        }
        delete[] pdata;
        pdata = newdata;
    }
};

// Специализация для char*
template <>
class MyVector<char*> {
protected:
    int maxsize;
    int size;
    char **pdata;

private:
    void resize() {
        maxsize *= 2;
        char **newdata = new char*[maxsize];
        for(int i = 0; i < size; i++) {
            newdata[i] = pdata[i];
        }
        delete[] pdata;
        pdata = newdata;
    }
public:
    explicit MyVector(const char *el = nullptr, int maxsz = MAX_SIZE) {
        size = 0;
        maxsize = maxsz;
        pdata = new char*[maxsize];
        if(el != nullptr) {
            add_element(el);
        }
    }

    MyVector(const MyVector<char*> &v) {
        size = v.size;
        maxsize = v.maxsize;
        pdata = new char*[maxsize];
        for(int i = 0; i < size; i++) {
            pdata[i] = new char[MAX_LENGTH];
            std::strcpy(pdata[i], v.pdata[i]);
        }
    }

    ~MyVector() {
        for(int i = 0; i < size; i++) {
            delete[] pdata[i];
        }
        delete[] pdata;
    }

    void add_element(const char *el) {
        if(size == maxsize) {
            resize();
        }
        pdata[size] = new char[MAX_LENGTH];
        std::strcpy(pdata[size], el);
        size++;
    }

    bool delete_element(int idx) {
        if(idx >= size) {
            return false;
        }
        delete[] pdata[idx];
        for(int i = idx; i < size-1; i++) {
            pdata[i] = pdata[i+1];
        }
        size--;
        return true;
    }

    char* operator[](int i) const {
        return pdata[i];
    }

    void sort() {
        if(size == 0) return;
        char max[MAX_LENGTH];
        for(int i = size; i > 0; i--) {
            int maxi = 0;
            std::strncpy(max, pdata[0], MAX_LENGTH);
            for(int j = 0; j < i; j++) {
                if(strcmp(pdata[j], max) > 0) {
                    std::strcpy(max, pdata[j]);
                    maxi = j;
                }
            }
            std::strcpy(pdata[maxi], pdata[i-1]);
            std::strcpy(pdata[i-1], max);
        }
    }

    [[nodiscard]] int Size() const { return size; }
    [[nodiscard]] int Maxsize() const { return maxsize; }

    int find(const char *el) const {
        for(int i = 0; i < size; i++) {
            if(std::strcmp(el, pdata[i]) == 0) {
                return i;
            }
        }
        return -1;
    }

    MyVector<char*> &operator=(const MyVector<char*> &v) {
        if(this == &v) return *this;
        for(int i = 0; i < size; i++) {
            delete[] pdata[i];
        }
        delete[] pdata;
        size = v.size;
        maxsize = v.maxsize;
        pdata = new char*[maxsize];
        for(int i = 0; i < size; i++) {
            pdata[i] = new char[MAX_LENGTH];
            std::strcpy(pdata[i], v.pdata[i]);
        }
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const MyVector<char*> &v) {
        for(int i = 0; i < v.size; i++) {
            out << v.pdata[i] << ' ';
        }
        return out;
    }

};

#endif //INHERITANCE_MYVECTOR_H