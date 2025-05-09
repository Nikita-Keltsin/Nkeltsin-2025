#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

class Complex {
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    
    // Сложение комплексных чисел
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    // Для накопления суммы
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }
    
    // Для сортировки по модулю
    bool operator<(const Complex& other) const {
        return (real*real + imag*imag) < (other.real*other.real + other.imag*other.imag);
    }
    
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.getReal();
    if (c.getImag() >= 0) {
        os << " + i*" << c.getImag();
    } else {
        os << " - i*" << -c.getImag();
    }
    return os;
}

void printComplexNumbers(const std::vector<Complex>& numbers) {
    for (const auto& n : numbers) {
        std::cout << n << std::endl;
    }
}

int main() {
    std::vector<Complex> numbers = {
        Complex(-1.2, 6.3),
        Complex(4.0, 0.7),
        Complex(7.2, -0.8),
        Complex(5.3, 3.0),
        Complex(-4.9, 6.6),
        Complex(-9.3, 0.2)
    };

    std::cout << "Комплексные числа:" << std::endl;
    printComplexNumbers(numbers);

    // Суммируем все числа
    Complex sum = std::accumulate(numbers.begin(), numbers.end(), Complex());
    std::cout << "\nСумма всех чисел: " << sum << std::endl;

    return 0;
}