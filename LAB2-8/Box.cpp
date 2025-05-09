#include <iostream>
#include <vector>
#include <algorithm>

class Box {
    double width, height, length;
public:
    Box(double w = 0.0, double h = 0.0, double l = 0.0)
        : width(w), height(h), length(l) {}
    
    double volume() const { return width * height * length; }
    double surfaceArea() const {
        return 2 * (width*height + width*length + height*length);
    }
    
    // Для сортировки по объему
    bool operator<(const Box& other) const {
        return volume() < other.volume();
    }
    
    // Для сравнения коробок
    bool operator==(const Box& other) const {
        return width == other.width && height == other.height && length == other.length;
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double getLength() const { return length; }
};

std::ostream& operator<<(std::ostream& os, const Box& b) {
    os << "Ширина: " << b.getWidth() << ", Высота: " << b.getHeight()
       << ", Длина: " << b.getLength() << ", Объем: " << b.volume()
       << ", Площадь поверхности: " << b.surfaceArea();
    return os;
}

void printBoxes(const std::vector<Box>& boxes) {
    for (const auto& b : boxes) {
        std::cout << b << std::endl;
    }
}

int main() {
    std::vector<Box> boxes = {
        Box(1, 2, 63),
        Box(14, 57, 19),
        Box(7, 32, 20),
        Box(5, 13, 23),
        Box(10, 19, 45),
        Box(19, 9, 59)
    };

    std::cout << "Все коробки:" << std::endl;
    printBoxes(boxes);

    // Находим коробку с максимальным объемом
    Box maxVolume = *std::max_element(boxes.begin(), boxes.end());
    std::cout << "\nКоробка с наибольшим объемом: " << maxVolume << std::endl;

    return 0;
}