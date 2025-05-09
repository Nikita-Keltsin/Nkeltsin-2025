#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Time {
    int hours, minutes, seconds;
public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}
    
    bool isNightTime() const {
        return hours >= 0 && hours < 5;
    }
    
    // Для сортировки времени
    bool operator<(const Time& other) const {
        if (hours != other.hours) return hours < other.hours;
        if (minutes != other.minutes) return minutes < other.minutes;
        return seconds < other.seconds;
    }
    
    // Для сравнения времени
    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }
    
    void print() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
};

void printTimes(const std::vector<Time>& times) {
    for (const auto& t : times) {
        t.print();
    }
}

int main() {
    std::vector<Time> times = {
        Time(1, 2, 63),
        Time(14, 57, 19),
        Time(7, 32, 20),
        Time(5, 13, 23),
        Time(10, 19, 45),
        Time(19, 9, 59)
    };

    std::cout << "Все время:" << std::endl;
    printTimes(times);

    // Создаем вектор с ночным временем
    std::vector<Time> nightTimes;
    std::copy_if(times.begin(), times.end(), std::back_inserter(nightTimes),
                 [](const Time& t) { return t.isNightTime(); });

    std::cout << "\nНочное время:" << std::endl;
    printTimes(nightTimes);

    return 0;
}