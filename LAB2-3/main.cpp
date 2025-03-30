#include "Fractions.hpp"
#include <iostream>

int main(){
    Fraction frac1, frac2;
    
    std::cout << "Введите первую дробь (формат a/b): ";
    std::cin >> frac1;
    
    std::cout << "Введите вторую дробь (формат a/b): ";
    std::cin >> frac2;
    
    std::cout << "user1: "; frac1.PrintFraction();
    std::cout << "user2: "; frac2.PrintFraction();

    Fraction sum = frac1 + frac2 ;
    Fraction diff = frac1 - frac2;
    Fraction prod = frac1 * frac2;
    Fraction quot = frac1 / frac2;
    
    std::cout << frac1 << " + " << frac2 << " = " << sum << std::endl;
    std::cout << frac1 << " - " << frac2 << " = " << diff << std::endl;
    std::cout << frac1 << " * " << frac2 << " = " << prod << std::endl;
    std::cout << frac1 << " / " << frac2 << " = " << quot << std::endl << std::endl;

    return 0;

}
