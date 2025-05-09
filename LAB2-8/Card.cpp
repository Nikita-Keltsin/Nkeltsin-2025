#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Card {
    std::string title;
    std::string author;
    int number;
public:
    Card(std::string t = "", std::string a = "", int n = 0) 
        : title(t), author(a), number(n) {}
    
    // Методы доступа
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getNumber() const { return number; }
    
    // Для сортировки по названию
    bool operator<(const Card& other) const {
        return title < other.title;
    }
};

std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << "\"" << c.getTitle() << "\" by " << c.getAuthor() 
       << " (в наличии: " << c.getNumber() << ")";
    return os;
}

void printCards(const std::vector<Card>& cards) {
    for (const auto& c : cards) {
        std::cout << c << std::endl;
    }
}

void findBooksByAuthor(const std::vector<Card>& cards, const std::string& author) {
    bool found = false;
    std::cout << "Книги автора " << author << ":" << std::endl;
    
    for (const auto& c : cards) {
        if (c.getAuthor() == author) {
            std::cout << "- " << c.getTitle() << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "Книги данного автора отсутствуют." << std::endl;
    }
}

int main() {
    std::vector<Card> cards = {
        {"Война и мир", "Толстой", 5},
        {"Преступление и наказание", "Достоевский", 3},
        {"1984", "Оруэлл", 2},
        {"Мастер и Маргарита", "Булгаков", 4},
        {"Анна Каренина", "Толстой", 3}
    };

    std::cout << "Каталог книг:" << std::endl;
    printCards(cards);

    std::string author;
    std::cout << "\nВведите имя автора для поиска: ";
    std::getline(std::cin, author);
    
    findBooksByAuthor(cards, author);

    return 0;
}