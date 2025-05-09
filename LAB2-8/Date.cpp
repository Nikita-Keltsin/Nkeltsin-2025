#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iomanip>

class Date {
    int day, month, year;
public:
    Date(int d = 1, int m = 1, int y = 1970) : day(d), month(m), year(y) {}
    
    bool isFuture() const {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        
        int currentYear = 1900 + ltm->tm_year;
        int currentMonth = 1 + ltm->tm_mon;
        int currentDay = ltm->tm_mday;
        
        if (year > currentYear) return true;
        if (year == currentYear && month > currentMonth) return true;
        if (year == currentYear && month == currentMonth && day > currentDay) return true;
        return false;
    }
    
    // Для сортировки дат
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
    
    // Для сравнения дат
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
    
    void print() const {
        std::cout << std::setw(2) << std::setfill('0') << day << "."
                  << std::setw(2) << std::setfill('0') << month << "."
                  << year << std::endl;
    }
};

void printDates(const std::vector<Date>& dates) {
    for (const auto& d : dates) {
        d.print();
    }
}

int main() {
    std::vector<Date> dates = {
        Date(1, 2, 1963),
        Date(14, 7, 1995),
        Date(7, 12, 2088),
        Date(5, 3, 2030),
        Date(24, 9, 2013),
        Date(19, 9, 2020)
    };

    std::cout << "Все даты:" << std::endl;
    printDates(dates);

    // Создаем вектор с будущими датами
    std::vector<Date> futureDates;
    std::copy_if(dates.begin(), dates.end(), std::back_inserter(futureDates),
                 [](const Date& d) { return d.isFuture(); });

    std::cout << "\nБудущие даты:" << std::endl;
    printDates(futureDates);

    return 0;
}