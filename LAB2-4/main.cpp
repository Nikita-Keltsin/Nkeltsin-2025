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
    
    return 0;
}