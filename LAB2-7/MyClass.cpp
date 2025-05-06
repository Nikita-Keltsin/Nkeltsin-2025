#include "MyClass.hpp"

// Реализация Organization
Organization::Organization(const std::string& name, const std::string& address, int employeeCount)
    : name(name), address(address), employeeCount(employeeCount) {
    std::cout << "Organization()" << std::endl;
}

Organization::~Organization() {
    std::cout << "~Organization()" << std::endl;
}

// Реализация InsuranceCompany
InsuranceCompany::InsuranceCompany(const std::string& name, const std::string& address, 
                                 int employeeCount, int policiesIssued, const std::string& specialization)
    : Organization(name, address, employeeCount), 
      policiesIssued(policiesIssued), specialization(specialization) {
    std::cout << "InsuranceCompany()" << std::endl;
}

InsuranceCompany::~InsuranceCompany() {
    std::cout << "~InsuranceCompany()" << std::endl;
}

void InsuranceCompany::show() const {
    std::cout << "Insurance Company: " << name << "\n"
              << "Address: " << address << "\n"
              << "Employees: " << employeeCount << "\n"
              << "Policies issued: " << policiesIssued << "\n"
              << "Specialization: " << specialization << "\n";
}

// Реализация ShipbuildingCompany
ShipbuildingCompany::ShipbuildingCompany(const std::string& name, const std::string& address, 
                                       int employeeCount, int shipsBuilt, const std::string& shipType)
    : Organization(name, address, employeeCount), 
      shipsBuilt(shipsBuilt), shipType(shipType) {
    std::cout << "ShipbuildingCompany()" << std::endl;
}

ShipbuildingCompany::~ShipbuildingCompany() {
    std::cout << "~ShipbuildingCompany()" << std::endl;
}

void ShipbuildingCompany::show() const {
    std::cout << "Shipbuilding Company: " << name << "\n"
              << "Address: " << address << "\n"
              << "Employees: " << employeeCount << "\n"
              << "Ships built: " << shipsBuilt << "\n"
              << "Ship type: " << shipType << "\n";
}

// Реализация Factory
Factory::Factory(const std::string& name, const std::string& address, 
                int employeeCount, const std::string& productType, int productionCapacity)
    : Organization(name, address, employeeCount), 
      productType(productType), productionCapacity(productionCapacity) {
    std::cout << "Factory()" << std::endl;
}

Factory::~Factory() {
    std::cout << "~Factory()" << std::endl;
}

void Factory::show() const {
    std::cout << "Factory: " << name << "\n"
              << "Address: " << address << "\n"
              << "Employees: " << employeeCount << "\n"
              << "Product type: " << productType << "\n"
              << "Production capacity: " << productionCapacity << "\n";
}