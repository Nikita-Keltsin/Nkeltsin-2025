#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Point {
public:
    double x, y;
    
    Point() : x(0), y(0) {}
    Point(double a, double b) : x(a), y(b) {}
    
    // Оператор сравнения для сортировки (по расстоянию от центра)
    bool operator<(const Point& other) const {
        return (x*x + y*y) < (other.x*other.x + other.y*other.y);
    }
    
    // Оператор равенства
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    // Метод для вычисления расстояния от центра
    double distanceFromOrigin() const {
        return std::sqrt(x*x + y*y);
    }
};

// Оператор вывода для точки
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

// Функция для вывода массива точек
void printPoints(const std::vector<Point>& points) {
    for (const auto& p : points) {
        std::cout << p << std::endl;
    }
}

int main() {
    // Создание и инициализация вектора точек
    std::vector<Point> points = {
        Point(1.2, 6.3),
        Point(4.0, 0.7),
        Point(7.2, 0.8),
        Point(5.3, 3.0),
        Point(4.9, 6.6),
        Point(9.3, 0.2)
    };
    
    // Вывод исходного массива точек
    std::cout << "Исходные точки:" << std::endl;
    printPoints(points);
    
    // Нахождение точки, наиболее удаленной от центра
    Point farthest = *std::max_element(points.begin(), points.end());
    std::cout << "\nСамая удаленная точка от центра: " << farthest 
              << " (расстояние: " << farthest.distanceFromOrigin() << ")" << std::endl;
    
    // Сдвиг всех точек по оси X
    double shift;
    std::cout << "\nВведите величину сдвига по оси X: ";
    std::cin >> shift;
    
    for (auto& p : points) {
        p.x -= shift;
    }
    
    // Вывод массива после сдвига
    std::cout << "\nТочки после сдвига:" << std::endl;
    printPoints(points);
    
    return 0;
}