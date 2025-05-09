#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Planet {
public:
    std::string name;
    int satellites;
    
    Planet(std::string n = "", int s = 0) : name(n), satellites(s) {}
    
    // Для сортировки по количеству спутников
    bool operator<(const Planet& other) const {
        return satellites < other.satellites;
    }
    
    // Для поиска по названию
    bool operator==(const std::string& planetName) const {
        return name == planetName;
    }
};

std::ostream& operator<<(std::ostream& os, const Planet& p) {
    os << p.name << " (" << p.satellites << " спутников)";
    return os;
}

void printPlanets(const std::vector<Planet>& planets) {
    for (const auto& p : planets) {
        std::cout << p << std::endl;
    }
}

int main() {
    std::vector<Planet> planets = {
        {"Меркурий", 0},
        {"Венера", 0},
        {"Земля", 1},
        {"Марс", 2},
        {"Юпитер", 69},
        {"Сатурн", 62},
        {"Уран", 27},
        {"Нептун", 14},
        {"Плутон", 10}
    };

    std::cout << "Список планет:" << std::endl;
    printPlanets(planets);

    // Находим планету с максимальным количеством спутников
    auto maxSatellites = std::max_element(planets.begin(), planets.end());
    std::cout << "\nПланета с наибольшим количеством спутников: " 
              << *maxSatellites << std::endl;

    return 0;
}