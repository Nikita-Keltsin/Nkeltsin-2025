#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <iostream>

class Term {
public:
    int coeff;
    int exp;
    
    Term(int c = 0, int e = 0) : coeff(c), exp(e) {}
};

class Polynomial {
private:
    std::vector<Term> terms;  // Теперь храним вектор Term вместо двух векторов
    
    void combineLikeTerms();

public:
    void addTerm(int coeff, int exp);  // Оставляем старый интерфейс
    
    friend std::istream& operator>>(std::istream& is, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
    
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
};

#endif