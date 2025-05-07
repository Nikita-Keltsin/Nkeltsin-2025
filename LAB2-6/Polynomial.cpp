#include "Polynomial.hpp"
#include <sstream>
#include <algorithm>
#include <cctype>

void Polynomial::addTerm(int coeff, int exp) {
    if (coeff == 0) return;
    terms.emplace_back(coeff, exp);
}

void Polynomial::combineLikeTerms() {
    // Объединяем одинаковые степени
    for (size_t i = 0; i < terms.size(); i++) {
        for (size_t j = i + 1; j < terms.size(); j++) {
            if (terms[i].exp == terms[j].exp) {
                terms[i].coeff += terms[j].coeff;
                terms[j].coeff = 0;
            }
        }
    }
    terms.erase(
        std::remove_if(terms.begin(), terms.end(), 
                      [](const Term& t) { return t.coeff == 0; }),
        terms.end());
    
    // Сортируем по убыванию степени
    std::sort(terms.begin(), terms.end(), 
              [](const Term& a, const Term& b) { return a.exp > b.exp; });
}

std::istream& operator>>(std::istream& is, Polynomial& p) {
    p.terms.clear();
    
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
    if (p.terms.empty()) {
        os << "0";
        return os;
    }
    
    for (size_t i = 0; i < p.terms.size(); i++) {
        const Term& term = p.terms[i];  // Работаем с объектом Term
        
        if (i > 0) {
            os << (term.coeff > 0 ? " + " : " - ");
        } else if (term.coeff < 0) {
            os << "-";
        }
        
        int abs_coeff = abs(term.coeff);
        if (abs_coeff != 1 || term.exp == 0) {
            os << abs_coeff;
        }
        
        if (term.exp > 0) {
            os << "x";
            if (term.exp > 1) {
                os << "^" << term.exp;
            }
        }
    }
    
    return os;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result;
    
    for (const Term& term : terms) {
        result.addTerm(term.coeff, term.exp);
    }
    
    for (const Term& term : other.terms) {
        result.addTerm(term.coeff, term.exp);
    }
    
    result.combineLikeTerms();
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result;
    
    for (const Term& t1 : terms) {
        for (const Term& t2 : other.terms) {
            result.addTerm(t1.coeff * t2.coeff, t1.exp + t2.exp);
        }
    }
    
    result.combineLikeTerms();
    return result;
}