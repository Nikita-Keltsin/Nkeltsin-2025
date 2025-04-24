#include <iostream>
#include "MyVector.hpp"
#include "MyVectorChar.hpp"
#include "MySet.hpp"
#include "MySetChar.hpp"

void demonstrate_vector() {
    std::cout << "=== Демонстрация MyVector<int> ===\n";
    MyVector<int> vec;
    
    vec.add_element(10);
    vec.add_element(20);
    vec.add_element(30);
    
    std::cout << "Вектор после добавления: ";
    for (size_t i = 0; i < vec.get_size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    
    vec.delete_element(1);
    std::cout << "После удаления элемента с индексом 1: ";
    for (size_t i = 0; i < vec.get_size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n\n";
}

void demonstrate_vector_char() {
    std::cout << "=== Демонстрация MyVector<char*> ===\n";
    MyVector<char*> vec;
    
    vec.add_element("apple");
    vec.add_element("banana");
    vec.add_element("orange");
    
    std::cout << "Вектор строк: ";
    for (size_t i = 0; i < vec.get_size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n\n";
}

void demonstrate_set() {
    std::cout << "=== Демонстрация MySet<int> ===\n";
    MySet<int> set1, set2;
    
    set1.add_element(1);
    set1.add_element(3);
    set1.add_element(5);
    
    set2.add_element(2);
    set2.add_element(3);
    set2.add_element(4);
    
    std::cout << "Множество 1: " << set1 << "\n";
    std::cout << "Множество 2: " << set2 << "\n";
    
    MySet<int> union_set = set1 + set2;
    MySet<int> intersect_set = set1 * set2;
    MySet<int> diff_set = set1 - set2;
    
    std::cout << "Объединение: " << union_set << "\n";
    std::cout << "Пересечение: " << intersect_set << "\n";
    std::cout << "Разность: " << diff_set << "\n";
    std::cout << "Сравнение: " << (set1 == set2 ? "равны" : "не равны") << "\n\n";
}

void demonstrate_set_char() {
    std::cout << "=== Демонстрация MySetChar ===\n";
    MySetChar set1, set2;
    
    set1.add_element("apple");
    set1.add_element("banana");
    set1.add_element("orange");
    
    set2.add_element("banana");
    set2.add_element("kiwi");
    set2.add_element("apple");
    
    std::cout << "Множество 1: " << set1 << "\n";
    std::cout << "Множество 2: " << set2 << "\n";
    
    MySetChar union_set = set1 + set2;
    MySetChar intersect_set = set1 * set2;
    MySetChar diff_set = set1 - set2;
    
    std::cout << "Объединение: " << union_set << "\n";
    std::cout << "Пересечение: " << intersect_set << "\n";
    std::cout << "Разность: " << diff_set << "\n";
    std::cout << "Сравнение: " << (set1 == set2 ? "равны" : "не равны") << "\n\n";
}

int main() {
    demonstrate_vector();
    demonstrate_vector_char();
    demonstrate_set();
    demonstrate_set_char();
    
    return 0;
}