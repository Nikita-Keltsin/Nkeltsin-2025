#include "Fractions.hpp"

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(const char *str) {
  numerator = 0;
  denominator = 1;

  int sign = 1;
  int i = 0;

  if (str[i] == '-') {
    sign = -1;
    i++;
  };

  while (isdigit(str[i])) {
    numerator = numerator * 10 + (str[i] - '0');
    i++;
  }
  numerator *= sign;
  if (str[i] == '/') {
    i++;
    denominator = 0;
    sign = 1;

    if (str[i] == '-') {
      sign = -1;
      i++;
    }
    while (isdigit(str[i])) {
      denominator = denominator * 10 + (str[i] - '0');
      i++;
    }
    denominator *= sign;
  }
  Reduce();
}
void Fraction::PrintFraction() const {
  std::cout << numerator << "/" << denominator << std::endl;
}
int Fraction::GCD(int a, int b) const {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
void Fraction::Reduce() {
  int commonDivisor = GCD(abs(numerator), abs(denominator));
  numerator /= commonDivisor;
  denominator /= commonDivisor;
  if (denominator < 0) {
    numerator *= -1;
    denominator *= -1;
  }
}
std::istream &operator>>(std::istream &in, Fraction &frac) {
  char overload[100];
  in >> overload;
  frac = Fraction(overload);
  return in;
}
std::ostream &operator<<(std::ostream &out, const Fraction &fract) {
  out << fract.numerator;
  if (fract.denominator != 1)
    out << '/' << fract.denominator;
  return out;
}
Fraction Fraction::operator+(const Fraction &other) const {
  int num = numerator * other.denominator + other.numerator * denominator;
  int denom = denominator * other.denominator;

  char buffer[50];
  char *ptr = buffer;

  if (num < 0) {
    *ptr++ = '-';
    num = -num;
  }
  int temp = num;
  int digits = 1;
  while (temp >= 10) {
    temp /= 10;
    digits++;
  }
  temp = num;
  for (int i = digits - 1; i >= 0; i--) {
    ptr[i] = '0' + temp % 10;
    temp /= 10;
  }
  ptr += digits;
  *ptr++ = '/';
  temp = denom;
  if (temp < 0) {
    *ptr++ = '-';
    temp = -temp;
  }
  digits = 1;
  while (temp >= 10) {
    temp /= 10;
    digits++;
  }
  temp = denom;
  if (temp < 0)
    temp = -temp;
  for (int i = digits - 1; i >= 0; i--) {
    ptr[i] = '0' + temp % 10;
    temp /= 10;
  }
  ptr += digits;
  *ptr = '\0';

  return Fraction(buffer);
}

Fraction Fraction::operator-(const Fraction &other) const {
  int num = numerator * other.denominator - other.numerator * denominator;
  int denom = denominator * other.denominator;
  char buffer[50];
  char *ptr = buffer;

  if (num < 0) {
    *ptr++ = '-';
    num = -num;
  }
  int temp = num;
  int digits = 1;
  while (temp >= 10) {
    temp /= 10;
    digits++;
  }
  temp = num;
  for (int i = digits - 1; i >= 0; i--) {
    ptr[i] = '0' + temp % 10;
    temp /= 10;
  }
  ptr += digits;

  *ptr++ = '/';
  temp = denom;
  if (temp < 0) {
    *ptr++ = '-';
    temp = -temp;
  }
  digits = 1;
  while (temp >= 10) {
    temp /= 10;
    digits++;
  }
  temp = denom;
  if (temp < 0)
    temp = -temp;
  for (int i = digits - 1; i >= 0; i--) {
    ptr[i] = '0' + temp % 10;
    temp /= 10;
  }
  ptr += digits;
  *ptr = '\0';

  return Fraction(buffer);
}

Fraction Fraction::operator*(const Fraction &other) const {
  int num = numerator * other.numerator;
  int denom = denominator * other.denominator;

  char buffer[50];
  char *ptr = buffer;

  if (num < 0) {
    *ptr++ = '-';
    num = -num;
  }
  int temp = num;
  int digits = 1;
  while (temp >= 10) {
    temp /= 10;
    digits++;
  }
  temp = num;
  for (int i = digits - 1; i >= 0; i--) {
    ptr[i] = '0' + temp % 10;
    temp /= 10;
  }
  ptr += digits;

  *ptr++ = '/';
  temp = denom;
  if (temp < 0) {
    *ptr++ = '-';
    temp = -temp;
  }
  digits = 1;
  while (temp >= 10) {
    temp /= 10;
    digits++;
  }
  temp = denom;
  if (temp < 0)
    temp = -temp;
  for (int i = digits - 1; i >= 0; i--) {
    ptr[i] = '0' + temp % 10;
    temp /= 10;
  }
  ptr += digits;
  *ptr = '\0';

  return Fraction(buffer);
}
Fraction Fraction::operator/(const Fraction &other) const {
  int num = numerator * other.denominator;
  int denom = denominator * other.numerator;
  char buffer[50];
  char *ptr = buffer;

  if (num < 0) {
    *ptr++ = '-';
    num = -num;
  }
  int temp = num;
  int digits = 1;
  while (temp >= 10) {
    temp /= 10;
    digits++;
  }
  temp = num;
  for (int i = digits - 1; i >= 0; i--) {
    ptr[i] = '0' + temp % 10;
    temp /= 10;
  }
  ptr += digits;

  *ptr++ = '/';
  temp = denom;
  if (temp < 0) {
    *ptr++ = '-';
    temp = -temp;
  }
  digits = 1;
  while (temp >= 10) {
    temp /= 10;
    digits++;
  }
  temp = denom;
  if (temp < 0)
    temp = -temp;
  for (int i = digits - 1; i >= 0; i--) {
    ptr[i] = '0' + temp % 10;
    temp /= 10;
  }
  ptr += digits;
  *ptr = '\0';

  return Fraction(buffer);
}
