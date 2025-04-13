#include <iostream>
#include "MyStack.hpp"

void Multipliers(int n, MyStack<int>& stack) {
    if (n < 2) {
        stack.push(n);
        return;
    }
    
    for (int divisor = 2; n > 1; ) {
        if (n % divisor == 0) {
            stack.push(divisor);
            n /= divisor;
        } else {
            divisor++;
        }
    }
}

void printStack(MyStack<int>& stack) {
    MyStack<int> temp;
    while (!stack.empty()) {
        temp.push(stack.top_inf());
        stack.pop();
    }
    
    bool first = true;
    while (!temp.empty()) {
        if (!first) std::cout << " * ";
        std::cout << temp.top_inf();
        stack.push(temp.top_inf());
        temp.pop();
        first = false;
    }
}

int main() {
    char continueprogramm = 'Y';
    int choice = 0;
    while (continueprogramm == 'Y'){
        std::cout << "1.Вывести множители для числа 3960" << std::endl;
        std::cout << "2.Вывести множители для числа пользователя" << std::endl;
        std::cin >> choice;
        if (choice == 1){
            int N = 3960;
            MyStack<int> stack;
            Multipliers(N, stack);
            // Вывод по убыванию (как хранится в стеке)
            std::cout << N << "=";
            MyStack<int> temp = stack;
            bool first = true;
            while (!temp.empty()) {
                if (!first) std::cout << " * ";
                std::cout << temp.top_inf();
                temp.pop();
                first = false;
            }
            std::cout << std::endl;
            // Вывод по возрастанию (перевернем стек)
            std::cout << N << "=";
            printStack(stack);
            std::cout << std::endl;
        }
        if (choice == 2){
            int N = 0;
            std::cout << "Введите значение N:";
            std::cin >> N;
            MyStack<int> stack;
    
            Multipliers(N, stack);
    
            // Вывод по убыванию (как хранится в стеке)
            std::cout << N << "=";
            MyStack<int> temp = stack;
            bool first = true;
            while (!temp.empty()) {
                if (!first) std::cout << " * ";
                std::cout << temp.top_inf();
                temp.pop();
                first = false;
            }
            std::cout << std::endl;
            // Вывод по возрастанию (перевернем стек)
            std::cout << N << "=";
            printStack(stack);
            std::cout << std::endl;
        }
        std::cout << "Продолжить программу?(Y/N)" << std::endl;
        std::cin >> continueprogramm;
        if (continueprogramm != 'Y'){
            std::cout << "До новых встреч!" << std::endl;
        }
    }
    return 0;
}