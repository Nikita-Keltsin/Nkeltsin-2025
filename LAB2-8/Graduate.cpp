#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

class Graduate {
    std::string name;
    double rating;
public:
    Graduate(std::string n = "", double r = 0.0) : name(n), rating(r) {}
    
    void increaseRating(double value) { rating += value; }
    
    // Для сортировки по рейтингу
    bool operator<(const Graduate& other) const {
        return rating < other.rating;
    }
    
    // Для сравнения выпускников
    bool operator==(const Graduate& other) const {
        return name == other.name && rating == other.rating;
    }
    
    std::string getName() const { return name; }
    double getRating() const { return rating; }
};

std::ostream& operator<<(std::ostream& os, const Graduate& g) {
    os << g.getName() << " (рейтинг: " << std::fixed << std::setprecision(2) << g.getRating() << ")";
    return os;
}

void printGraduates(const std::vector<Graduate>& grads) {
    for (const auto& g : grads) {
        std::cout << g << std::endl;
    }
}

int main() {
    std::vector<Graduate> grads = {
        Graduate("Иванов", 99),
        Graduate("Петров", 430),
        Graduate("Семенов", 70),
        Graduate("Котов", 540),
        Graduate("Белых", 230),
        Graduate("Черных", 350)
    };

    std::cout << "Все выпускники:" << std::endl;
    printGraduates(grads);

    // Находим выпускника с максимальным рейтингом
    Graduate maxRating = *std::max_element(grads.begin(), grads.end());
    std::cout << "\nВыпускник с максимальным рейтингом: " << maxRating << std::endl;

    // Увеличиваем рейтинг всем выпускникам
    double increase;
    std::cout << "\nВведите величину увеличения рейтинга: ";
    std::cin >> increase;
    
    for (auto& g : grads) {
        g.increaseRating(increase);
    }

    std::cout << "\nВыпускники после увеличения рейтинга:" << std::endl;
    printGraduates(grads);

    return 0;
}