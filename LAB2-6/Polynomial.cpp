#include "Polynomial.hpp"
#include <algorithm>

Polynomial::Polynomial() : capacity(10), size(0) {
    terms = new Term[capacity];
}

Polynomial::~Polynomial() {
    delete[] terms;
}

void Polynomial::resize() {
    capacity *= 2;
    Term* new_terms = new Term[capacity];
    for (int i = 0; i < size; i++) {
        new_terms[i] = terms[i];
    }
    delete[] terms;
    terms = new_terms;
}

void Polynomial::sort() {
    // Сортировка по убыванию степени
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (terms[j].exp < terms[j+1].exp) {
                std::swap(terms[j], terms[j+1]);
            }
        }
    }
}

void Polynomial::addTerm(const Term& t) {
    if (size >= capacity) resize();
    terms[size++] = t;
}

void Polynomial::simplify() {
    sort();
    
    int new_size = 0;
    for (int i = 0; i < size; i++) {
        if (new_size > 0 && terms[new_size-1].exp == terms[i].exp) {
            terms[new_size-1].coeff += terms[i].coeff;
        } else {
            terms[new_size++] = terms[i];
        }
    }
    size = new_size;
}

std::istream& operator>>(std::istream& in, Polynomial& p) {
    p.size = 0;
    Term t;
    char ch;
    
    while (true) {
        // Пропускаем пробелы
        while (in.get(ch) && isspace(ch)) {}
        if (!in) break;
        
        if (ch == '\n') break;
        
        // Возвращаем символ обратно
        in.putback(ch);
        
        // Читаем коэффициент
        t.coeff = 1;
        int sign = 1;
        if (in.peek() == '-') {
            sign = -1;
            in.get(ch);
        } else if (in.peek() == '+') {
            in.get(ch);
        }
        
        if (isdigit(in.peek())) {
            in >> t.coeff;
        }
        t.coeff *= sign;
        
        // Читаем переменную и степень
        t.exp = 0;
        if (in.peek() == 'x') {
            in.get(ch);
            t.exp = 1;
            if (in.peek() == '^') {
                in.get(ch);
                in >> t.exp;
            }
        }
        
        p.addTerm(t);
        
        // Пропускаем пробелы после терма
        while (in.get(ch) && isspace(ch)) {}
        if (!in || ch == '\n') break;
        in.putback(ch);
    }
    
    p.simplify();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    if (p.size == 0) {
        out << "0";
        return out;
    }
    
    for (int i = 0; i < p.size; i++) {
        const Term& t = p.terms[i];
        
        if (i > 0 && t.coeff > 0) out << " + ";
        else if (i > 0) out << " - ";
        else if (t.coeff < 0) out << "-";
        
        int abs_coeff = abs(t.coeff);
        if (abs_coeff != 1 || t.exp == 0) {
            out << abs_coeff;
        }
        
        if (t.exp > 0) {
            out << "x";
            if (t.exp > 1) {
                out << "^" << t.exp;
            }
        }
    }
    
    return out;
}

Polynomial Polynomial::operator+(const Polynomial& other) {
    Polynomial result;
    for (int i = 0; i < size; i++) result.addTerm(terms[i]);
    for (int i = 0; i < other.size; i++) result.addTerm(other.terms[i]);
    result.simplify();
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& other) {
    Polynomial result;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < other.size; j++) {
            Term t;
            t.coeff = terms[i].coeff * other.terms[j].coeff;
            t.exp = terms[i].exp + other.terms[j].exp;
            result.addTerm(t);
        }
    }
    result.simplify();
    return result;
}