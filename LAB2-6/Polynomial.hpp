#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <iostream>

class Polynomial {
private:
    std::vector<int> coeffs;
    std::vector<int> exps;
    
    void combineLikeTerms();

public:
    void addTerm(int coeff, int exp);
    
    friend std::istream& operator>>(std::istream& is, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
    
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
};

#endif