#include "Polynomial.hpp"
#include <iostream>

int main() {
    Polynomial p1, p2;
    
    std::cout << "Введите первый многочлен: ";
    std::cin >> p1;
    
    std::cout << "Введите второй многочлен: ";
    std::cin >> p2;
    
    Polynomial sum = p1 + p2;
    std::cout << "Сумма: " << p1 << " + " << p2 << " = " << sum << std::endl;
    
    Polynomial product = p1 * p2;
    std::cout << "Произведение: " << p1 << " * " << p2 << " = " << product << std::endl;
    
    return 0;
}