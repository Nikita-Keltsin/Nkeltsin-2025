#include <iostream>
#include "MyClass.hpp"
#include "MyVector.hpp"

void print(const MyVector<Organization*>& container) {
    if (container.getSize() == 0) {
        std::cout << "Container is empty.\n";
        return;
    }
    for (size_t i = 0; i < container.getSize(); ++i) {
        std::cout << "\nIndex " << i << ":\n";
        container[i]->show();
    }
}

void remove(MyVector<Organization*>& container, size_t index) {
    if (index < container.getSize()) {
        delete container[index];
        container.remove(index);
        std::cout << "Removed element at index " << index << "\n";
    } else {
        std::cout << "Invalid index!\n";
    }
}

void clear(MyVector<Organization*>& container) {
    for (size_t i = 0; i < container.getSize(); ++i) {
        delete container[i];
    }
    container.clear();
    std::cout << "Container cleared.\n";
}

void demoMode() {
    MyVector<Organization*> orgs;
    
    std::cout << "\n=== DEMO MODE ===\n";
    
    // 1. Добавление объектов
    orgs.push_back(new InsuranceCompany("SafeLife", "123 Insurance St", 200, 5000, "Life"));
    orgs.push_back(new ShipbuildingCompany("OceanMaster", "456 Harbor Ave", 1500, 45, "Container"));
    orgs.push_back(new Factory("SteelWorks", "789 Industrial Blvd", 800, "Steel", 10000));
    std::cout << "Added 3 organizations.\n";
    
    // 2. Вывод
    std::cout << "\nCurrent organizations:\n";
    print(orgs);
    
    // 3. Удаление
    std::cout << "\nRemoving organization at index 1...\n";
    remove(orgs, 1);
    
    // 4. Вывод после удаления
    std::cout << "\nAfter removal:\n";
    print(orgs);
    
    // 5. Очистка
    std::cout << "\nClearing container...\n";
    clear(orgs);
    
    // 6. Проверка
    std::cout << "\nFinal state:\n";
    print(orgs);
}

void interactiveMode() {
    MyVector<Organization*> orgs;
    int choice;
    
    do {
        std::cout << "\n=== INTERACTIVE MODE ===\n"
                  << "1. Add Insurance Company\n"
                  << "2. Add Shipbuilding Company\n"
                  << "3. Add Factory\n"
                  << "4. Print all\n"
                  << "5. Remove by index\n"
                  << "6. Clear container\n"
                  << "0. Back to main menu\n"
                  << "Choice: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1: {
                std::string name, address, spec;
                int employees, policies;
                
                std::cout << "Name: "; std::cin.ignore(); std::getline(std::cin, name);
                std::cout << "Address: "; std::getline(std::cin, address);
                std::cout << "Employees: "; std::cin >> employees;
                std::cout << "Policies: "; std::cin >> policies;
                std::cout << "Specialization: "; std::cin.ignore(); std::getline(std::cin, spec);
                
                orgs.push_back(new InsuranceCompany(name, address, employees, policies, spec));
                std::cout << "Added.\n";
                break;
            }
            case 2: {
                std::string name, address, type;
                int employees, ships;
                
                std::cout << "Name: "; std::cin.ignore(); std::getline(std::cin, name);
                std::cout << "Address: "; std::getline(std::cin, address);
                std::cout << "Employees: "; std::cin >> employees;
                std::cout << "Ships built: "; std::cin >> ships;
                std::cout << "Ship type: "; std::cin.ignore(); std::getline(std::cin, type);
                
                orgs.push_back(new ShipbuildingCompany(name, address, employees, ships, type));
                std::cout << "Added.\n";
                break;
            }
            case 3: {
                std::string name, address, product;
                int employees, capacity;
                
                std::cout << "Name: "; std::cin.ignore(); std::getline(std::cin, name);
                std::cout << "Address: "; std::getline(std::cin, address);
                std::cout << "Employees: "; std::cin >> employees;
                std::cout << "Product: "; std::cin.ignore(); std::getline(std::cin, product);
                std::cout << "Capacity: "; std::cin >> capacity;
                
                orgs.push_back(new Factory(name, address, employees, product, capacity));
                std::cout << "Added.\n";
                break;
            }
            case 4: print(orgs); break;
            case 5: {
                size_t index;
                std::cout << "Index to remove: "; std::cin >> index;
                remove(orgs, index);
                break;
            }
            case 6: clear(orgs); break;
            case 0: clear(orgs); break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        std::cout << "\n=== MAIN MENU ===\n"
                  << "1. Demo mode\n"
                  << "2. Interactive mode\n"
                  << "0. Exit\n"
                  << "Choice: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1: demoMode(); break;
            case 2: interactiveMode(); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    
    return 0;
}