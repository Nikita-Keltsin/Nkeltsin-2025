#include <iostream>
#include <vector>
#include <algorithm>

class Rectangle {
    double width;
    double height;
public:
    Rectangle(double w = 0.0, double h = 0.0) : width(w), height(h) {}
    
    double area() const { return width * height; }
    double perimeter() const { return 2 * (width + height); }
    
    // Для сортировки по площади
    bool operator<(const Rectangle& other) const {
        return area() < other.area();
    }
    
    // Для сравнения прямоугольников
    bool operator==(const Rectangle& other) const {
        return width == other.width && height == other.height;
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    os << "Ширина: " << r.getWidth() << ", Высота: " << r.getHeight() 
       << ", Площадь: " << r.area() << ", Периметр: " << r.perimeter();
    return os;
}

void printRectangles(const std::vector<Rectangle>& rects) {
    for (const auto& r : rects) {
        std::cout << r << std::endl;
    }
}

int main() {
    std::vector<Rectangle> rects = {
        Rectangle(1.2, 6.3),
        Rectangle(4.0, 0.7),
        Rectangle(7.2, 0.8),
        Rectangle(5.3, 3.0),
        Rectangle(4.9, 6.6),
        Rectangle(9.3, 0.2)
    };

    std::cout << "Прямоугольники:" << std::endl;
    printRectangles(rects);

    // Находим прямоугольник с максимальной площадью
    Rectangle maxArea = *std::max_element(rects.begin(), rects.end());
    std::cout << "\nПрямоугольник с наибольшей площадью: " << maxArea << std::endl;

    return 0;
}