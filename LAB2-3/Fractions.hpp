#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include <cmath>

class Fraction {
private:
    int numerator;  
    int denominator;
    void Reduce();
    int GCD(int a, int b) const;

public:
    Fraction();
    Fraction(const char* str);
    void PrintFraction() const;
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
};
