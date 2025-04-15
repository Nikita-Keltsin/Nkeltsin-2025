#include <iostream>
#include <algorithm>
#include <cstring>
template <typename T>
class MyVector{
protected:
    size_t max_size;
    size_t size;
    T* pdata;
    void resize(size_t new_max_size){
        T* new_data = new T[new_max_size];
        for (int i = 0; i < size; i++){
            new_data[i] = pdata[i];
        }
        delete[] pdata;
        pdata = new_data;
        max_size = new_max_size;
    }
public:
    MyVector(size_t initial_size = 1) : max_size(initial_size), size(0), pdata(new T[initial_size]){}
    MyVector(const MyVector& other) : max_size(other.max_size), size(other.size), pdata(new T[other.max_size]){
        for (int i = 0; i < size; i++){
            pdata[i] = other.pdata[i];
        }
    }
    virtual ~MyVector(){
        delete[] pdata;
    }
    virtual void add_element(const T& element) {
    if (size >= max_size) {
        resize(max_size * 2);  // Увеличиваем размер при необходимости
    }
    pdata[size++] = element;  // Добавляем элемент
    }   

    virtual void delete_element(size_t index) {
    if (index >= size) return;  // Проверка границ
    // Сдвигаем элементы
    for (size_t i = index; i < size - 1; ++i) {
        pdata[i] = pdata[i + 1];
    }
    size--;
    
    // Уменьшаем размер если много свободного места
    if (size < max_size / 4 && max_size > 1) {
        resize(std::max(max_size / 2, static_cast<size_t>(1)));
    }
    }

    int find(const T& element) const {
        for (size_t i = 0; i < size; ++i) {
            if (pdata[i] == element) {
                return static_cast<int>(i);  // Линейный поиск
            }
        }
        return -1;  // Не найдено
    }


};