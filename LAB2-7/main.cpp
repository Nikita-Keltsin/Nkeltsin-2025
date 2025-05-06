#include <iostream>
#include <memory>
#include "MyClass.hpp"
#include "MyVector.hpp"

void print(const MyVector<Organization*>& container) {
    for (size_t i = 0; i < container.getSize(); ++i) {
        std::cout << "Index: " << i << "\n";
        container[i]->show();
        std::cout << "-----------------\n";
    }
}

void remove(MyVector<Organization*>& container, size_t index) {
    if (index < container.getSize()) {
        delete container[index];
        container.remove(index);
    }
}

void clear(MyVector<Organization*>& container) {
    for (size_t i = 0; i < container.getSize(); ++i) {
        delete container[i];
    }
    container.clear();
}

void demoMode() {
    std::cout << "=== DEMO MODE ===\n";
    
    MyVector<Organization*> organizations;
    
    // Добавление объектов
    organizations.push_back(new InsuranceCompany("SafeLife", "123 Insurance St", 200, 5000, "Life insurance"));
    organizations.push_back(new ShipbuildingCompany("OceanMaster", "456 Harbor Ave", 1500, 45, "Container ships"));
    organizations.push_back(new Factory("SteelWorks", "789 Industrial Blvd", 800, "Steel beams", 10000));
    
    // Вывод всех объектов
    std::cout << "\nAll organizations:\n";
    print(organizations);
    
    // Удаление одного объекта
    std::cout << "\nRemoving organization at index 1...\n";
    remove(organizations, 1);
    
    // Вывод после удаления
    std::cout << "\nAfter removal:\n";
    print(organizations);
    
    // Очистка контейнера
    std::cout << "\nClearing container...\n";
    clear(organizations);
    
    std::cout << "\nContainer size after clear: " << organizations.getSize() << "\n";
}

void interactiveMode() {
    MyVector<Organization*> organizations;
    int choice;
    
    do {
        std::cout << "\n=== MENU ===\n"
                  << "1. Add Insurance Company\n"
                  << "2. Add Shipbuilding Company\n"
                  << "3. Add Factory\n"
                  << "4. Print all organizations\n"
                  << "5. Remove organization\n"
                  << "6. Clear container\n"
                  << "0. Exit\n"
                  << "Your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                std::string name, address, specialization;
                int employees, policies;
                
                std::cout << "Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                
                std::cout << "Address: ";
                std::getline(std::cin, address);
                
                std::cout << "Employee count: ";
                std::cin >> employees;
                
                std::cout << "Policies issued: ";
                std::cin >> policies;
                
                std::cout << "Specialization: ";
                std::cin.ignore();
                std::getline(std::cin, specialization);
                
                organizations.push_back(new InsuranceCompany(name, address, employees, policies, specialization));
                break;
            }
            case 2: {
                std::string name, address, shipType;
                int employees, ships;
                
                std::cout << "Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                
                std::cout << "Address: ";
                std::getline(std::cin, address);
                
                std::cout << "Employee count: ";
                std::cin >> employees;
                
                std::cout << "Ships built: ";
                std::cin >> ships;
                
                std::cout << "Ship type: ";
                std::cin.ignore();
                std::getline(std::cin, shipType);
                
                organizations.push_back(new ShipbuildingCompany(name, address, employees, ships, shipType));
                break;
            }
            case 3: {
                std::string name, address, productType;
                int employees, capacity;
                
                std::cout << "Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                
                std::cout << "Address: ";
                std::getline(std::cin, address);
                
                std::cout << "Employee count: ";
                std::cin >> employees;
                
                std::cout << "Product type: ";
                std::cin.ignore();
                std::getline(std::cin, productType);
                
                std::cout << "Production capacity: ";
                std::cin >> capacity;
                
                organizations.push_back(new Factory(name, address, employees, productType, capacity));
                break;
            }
            case 4:
                print(organizations);
                break;
            case 5: {
                size_t index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                remove(organizations, index);
                break;
            }
            case 6:
                clear(organizations);
                std::cout << "Container cleared.\n";
                break;
            case 0:
                clear(organizations);
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

int main() {
    int mode;
    std::cout << "Select mode:\n1. Demo mode\n2. Interactive mode\nChoice: ";
    std::cin >> mode;
    
    if (mode == 1) {
        demoMode();
    } else if (mode == 2) {
        interactiveMode();
    } else {
        std::cout << "Invalid choice.\n";
    }
    
    return 0;
}