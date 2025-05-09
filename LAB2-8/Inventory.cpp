#include <iostream>
#include <vector>
#include <algorithm>

class Inventory {
    std::string item;
    double cost;
    int on_hand;
public:
    Inventory(std::string i = "", double c = 0.0, int o = 0)
        : item(i), cost(c), on_hand(o) {}
    
    // Для сортировки по названию товара
    bool operator<(const Inventory& other) const {
        return item < other.item;
    }
    
    // Для сравнения товаров
    bool operator==(const Inventory& other) const {
        return item == other.item && cost == other.cost && on_hand == other.on_hand;
    }
    
    std::string getItem() const { return item; }
    double getCost() const { return cost; }
    int getOnHand() const { return on_hand; }
    
    bool isOutOfStock() const { return on_hand == 0; }
};

std::ostream& operator<<(std::ostream& os, const Inventory& inv) {
    os << inv.getItem() << " - " << inv.getCost() << " - " << inv.getOnHand();
    return os;
}

void printInventory(const std::vector<Inventory>& items) {
    for (const auto& i : items) {
        std::cout << i << std::endl;
    }
}

int main() {
    std::vector<Inventory> items = {
        Inventory("Отвертка", 99, 0),
        Inventory("Молоток", 430, 10),
        Inventory("Гайки", 70, 100),
        Inventory("Профиль", 540, 0),
        Inventory("Уголок", 230, 9),
        Inventory("Доска", 350, 17)
    };

    std::cout << "Весь инвентарь:" << std::endl;
    printInventory(items);

    // Создаем вектор с отсутствующими товарами
    std::vector<Inventory> outOfStock;
    std::copy_if(items.begin(), items.end(), std::back_inserter(outOfStock),
                 [](const Inventory& i) { return i.isOutOfStock(); });

    std::cout << "\nОтсутствующие товары:" << std::endl;
    printInventory(outOfStock);

    return 0;
}