#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>

class Term {
public:
    int coeff;  // коэффициент
    int exp;    // степень x
    
    Term(int c = 0, int e = 0) : coeff(c), exp(e) {}
};

class Polynomial {
private:
    Term* terms;    // массив термов
    int capacity;   // размер массива
    int size;       // текущее количество термов
    
    void resize();   // увеличить размер массива
    void sort();     // сортировка по степеням
    
public:
    Polynomial();
    ~Polynomial();
    
    void addTerm(const Term& t);  // добавить терм
    void simplify();              // упростить (объединить одинаковые степени)
    
    friend std::istream& operator>>(std::istream& in, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);
    
    Polynomial operator+(const Polynomial& other);
    Polynomial operator*(const Polynomial& other);
};

#endif