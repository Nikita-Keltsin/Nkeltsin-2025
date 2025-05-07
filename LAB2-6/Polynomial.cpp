#include "Polynomial.hpp"
#include <sstream>
#include <algorithm>
#include <cctype>

void Polynomial::addTerm(int coeff, int exp) {
    if (coeff == 0) return;
    coeffs.push_back(coeff);
    exps.push_back(exp);
}

void Polynomial::combineLikeTerms() {
    // Объединяем одинаковые степени
    for (size_t i = 0; i < exps.size(); i++) {
        for (size_t j = i + 1; j < exps.size(); j++) {
            if (exps[i] == exps[j]) {
                coeffs[i] += coeffs[j];
                coeffs[j] = 0; // Помечаем для удаления
            }
        }
    }
    
    // Удаляем нулевые коэффициенты
    size_t new_size = 0;
    for (size_t i = 0; i < coeffs.size(); i++) {
        if (coeffs[i] != 0) {
            coeffs[new_size] = coeffs[i];
            exps[new_size] = exps[i];
            new_size++;
        }
    }
    coeffs.resize(new_size);
    exps.resize(new_size);
    
    // Сортируем по убыванию степени
    for (size_t i = 0; i < exps.size(); i++) {
        for (size_t j = i + 1; j < exps.size(); j++) {
            if (exps[i] < exps[j]) {
                std::swap(exps[i], exps[j]);
                std::swap(coeffs[i], coeffs[j]);
            }
        }
    }
}

std::istream& operator>>(std::istream& is, Polynomial& p) {
    p.coeffs.clear();
    p.exps.clear();
    
    std::string line;
    getline(is, line);
    std::istringstream iss(line);
    
    char ch;
    int coeff, exp;
    int sign = 1;
    
    while (iss >> std::ws) {
        if (iss.eof()) break;
        
        // Обработка знака
        sign = 1;
        ch = iss.peek();
        if (ch == '-' || ch == '+') {
            iss.get();
            if (ch == '-') sign = -1;
            // Пропускаем пробелы после знака
            while (iss.peek() == ' ') iss.get();
        }
        
        // Чтение коэффициента
        coeff = 1;
        if (isdigit(iss.peek())) {
            iss >> coeff;
        }
        coeff *= sign;
        
        // Чтение степени
        exp = 0;
        if (iss.peek() == 'x') {
            iss.get();
            exp = 1;
            if (iss.peek() == '^') {
                iss.get();
                iss >> exp;
            }
        }
        
        p.addTerm(coeff, exp);
    }
    
    p.combineLikeTerms();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    if (p.coeffs.empty()) {
        os << "0";
        return os;
    }
    
    for (size_t i = 0; i < p.coeffs.size(); i++) {
        int coeff = p.coeffs[i];
        int exp = p.exps[i];
        
        // Вывод знака
        if (i > 0) {
            os << (coeff > 0 ? " + " : " - ");
        } else if (coeff < 0) {
            os << "-";
        }
        
        // Вывод коэффициента
        int abs_coeff = abs(coeff);
        if (abs_coeff != 1 || exp == 0) {
            os << abs_coeff;
        }
        
        // Вывод переменной
        if (exp > 0) {
            os << "x";
            if (exp > 1) {
                os << "^" << exp;
            }
        }
    }
    
    return os;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result;
    
    // Копируем все члены из текущего многочлена
    for (size_t i = 0; i < coeffs.size(); i++) {
        result.addTerm(coeffs[i], exps[i]);
    }
    
    // Добавляем все члены из другого многочлена
    for (size_t i = 0; i < other.coeffs.size(); i++) {
        result.addTerm(other.coeffs[i], other.exps[i]);
    }
    
    result.combineLikeTerms();
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result;
    
    // Перемножаем каждый член первого многочлена с каждым членом второго
    for (size_t i = 0; i < coeffs.size(); i++) {
        for (size_t j = 0; j < other.coeffs.size(); j++) {
            int new_coeff = coeffs[i] * other.coeffs[j];
            int new_exp = exps[i] + other.exps[j];
            result.addTerm(new_coeff, new_exp);
        }
    }
    
    result.combineLikeTerms();
    return result;
}