#include <iostream>
#include "MyClass.hpp"
#include "MyVector.hpp"

void print(const MyVector<Organization*>& container) {
    if (container.getSize() == 0) {
        std::cout << "Container is empty.\n";
        return;
    }
    
    for (size_t i = 0; i < container.getSize(); ++i) {
        std::cout << "\nIndex: " << i << "\n";
        container[i]->show();
        std::cout << "-----------------";
    }
    std::cout << "\n";
}

void remove(MyVector<Organization*>& container, size_t index) {
    if (index < container.getSize()) {
        delete container[index];
        container.remove(index);
        std::cout << "Element at index " << index << " removed.\n";
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

void addDemoData(MyVector<Organization*>& container) {
    container.push_back(new InsuranceCompany("SafeLife", "123 Insurance St", 200, 5000, "Life insurance"));
    container.push_back(new ShipbuildingCompany("OceanMaster", "456 Harbor Ave", 1500, 45, "Container ships"));
    container.push_back(new Factory("SteelWorks", "789 Industrial Blvd", 800, "Steel beams", 10000));
    std::cout << "Demo data added.\n";
}

void addInsuranceCompany(MyVector<Organization*>& container) {
    std::string name, address, specialization;
    int employees, policies;
    
    std::cout << "Enter insurance company details:\n";
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
    
    container.push_back(new InsuranceCompany(name, address, employees, policies, specialization));
    std::cout << "Insurance company added.\n";
}

void addShipbuildingCompany(MyVector<Organization*>& container) {
    std::string name, address, shipType;
    int employees, ships;
    
    std::cout << "Enter shipbuilding company details:\n";
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
    
    container.push_back(new ShipbuildingCompany(name, address, employees, ships, shipType));
    std::cout << "Shipbuilding company added.\n";
}

void addFactory(MyVector<Organization*>& container) {
    std::string name, address, productType;
    int employees, capacity;
    
    std::cout << "Enter factory details:\n";
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
    
    container.push_back(new Factory(name, address, employees, productType, capacity));
    std::cout << "Factory added.\n";
}

void showMenu() {
    std::cout << "\n=== MAIN MENU ===\n"
              << "1. Add demo data\n"
              << "2. Add Insurance Company\n"
              << "3. Add Shipbuilding Company\n"
              << "4. Add Factory\n"
              << "5. Print all organizations\n"
              << "6. Remove organization\n"
              << "7. Clear container\n"
              << "0. Exit\n"
              << "Your choice: ";
}

int main() {
    MyVector<Organization*> organizations;
    int choice;
    
    do {
        showMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addDemoData(organizations);
                break;
            case 2:
                addInsuranceCompany(organizations);
                break;
            case 3:
                addShipbuildingCompany(organizations);
                break;
            case 4:
                addFactory(organizations);
                break;
            case 5:
                print(organizations);
                break;
            case 6: {
                size_t index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                remove(organizations, index);
                break;
            }
            case 7:
                clear(organizations);
                break;
            case 0:
                clear(organizations);
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}