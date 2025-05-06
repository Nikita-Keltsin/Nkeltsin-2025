#include "MyClass.hpp"

Organization::Organization(const std::string& name, const std::string& address, int employeeCount)
    : name(name), address(address), employeeCount(employeeCount) {}

Organization::~Organization() {}

InsuranceCompany::InsuranceCompany(const std::string& name, const std::string& address,
                                int employeeCount, int policiesIssued, const std::string& specialization)
    : Organization(name, address, employeeCount),
      policiesIssued(policiesIssued), specialization(specialization) {}

InsuranceCompany::~InsuranceCompany() {}

void InsuranceCompany::show() const {
    std::cout << "Insurance Company: " << name << "\n"
              << "Address: " << address << "\n"
              << "Employees: " << employeeCount << "\n"
              << "Policies issued: " << policiesIssued << "\n"
              << "Specialization: " << specialization << "\n";
}

ShipbuildingCompany::ShipbuildingCompany(const std::string& name, const std::string& address,
                                      int employeeCount, int shipsBuilt, const std::string& shipType)
    : Organization(name, address, employeeCount),
      shipsBuilt(shipsBuilt), shipType(shipType) {}

ShipbuildingCompany::~ShipbuildingCompany() {}

void ShipbuildingCompany::show() const {
    std::cout << "Shipbuilding Company: " << name << "\n"
              << "Address: " << address << "\n"
              << "Employees: " << employeeCount << "\n"
              << "Ships built: " << shipsBuilt << "\n"
              << "Ship type: " << shipType << "\n";
}

Factory::Factory(const std::string& name, const std::string& address,
               int employeeCount, const std::string& productType, int productionCapacity)
    : Organization(name, address, employeeCount),
      productType(productType), productionCapacity(productionCapacity) {}

Factory::~Factory() {}

void Factory::show() const {
    std::cout << "Factory: " << name << "\n"
              << "Address: " << address << "\n"
              << "Employees: " << employeeCount << "\n"
              << "Product type: " << productType << "\n"
              << "Production capacity: " << productionCapacity << "\n";
}