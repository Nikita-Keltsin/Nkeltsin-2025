#include <iostream>
#include "Polynomial.hpp"

void clearInput() {
    std::cin.clear();
    while (std::cin.get() != '\n') continue;
}

int main() {
    Polynomial p1, p2;
    int choice;
    
    do {
        std::cout << "\nКалькулятор многочленов\n";
        std::cout << "1. Ввести первый многочлен\n";
        std::cout << "2. Ввести второй многочлен\n";
        std::cout << "3. Сложить многочлены\n";
        std::cout << "4. Умножить многочлены\n";
        std::cout << "5. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        clearInput();
        
        switch (choice) {
            case 1:
                std::cout << "Введите первый многочлен (пример: 3x^2 - x + 5): ";
                std::cin >> p1;
                break;
                
            case 2:
                std::cout << "Enter second polynomial: ";
                std::cin >> p2;
                break;
                
            case 3: {
                Polynomial sum = p1 + p2;
                std::cout << "Сумма: " << p1 << " + " << p2 << " = " << sum << std::endl;
                break;
            }
                
            case 4: {
                Polynomial product = p1 * p2;
                std::cout << "Произведение: " << p1 << " * " << p2 << " = " << product << std::endl;
                break;
            }
                
            case 5:
                std::cout << "До скорого!\n";
                break;
                
            default:
                std::cout << "Неверный выбор. Попробуй снова.\n";
        }
    } while (choice != 5);
    
    return 0;
}