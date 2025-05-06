#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <iostream>
#include <string>

class Organization {
protected:
    std::string name;
    std::string address;
    int employeeCount;

public:
    Organization(const std::string& name, const std::string& address, int employeeCount);
    virtual ~Organization();
    virtual void show() const = 0;
};

class InsuranceCompany : public Organization {
protected:
    int policiesIssued;
    std::string specialization;

public:
    InsuranceCompany(const std::string& name, const std::string& address, 
                   int employeeCount, int policiesIssued, const std::string& specialization);
    ~InsuranceCompany() override;
    void show() const override;
};

class ShipbuildingCompany : public Organization {
protected:
    int shipsBuilt;
    std::string shipType;

public:
    ShipbuildingCompany(const std::string& name, const std::string& address,
                      int employeeCount, int shipsBuilt, const std::string& shipType);
    ~ShipbuildingCompany() override;
    void show() const override;
};

class Factory : public Organization {
protected:
    std::string productType;
    int productionCapacity;

public:
    Factory(const std::string& name, const std::string& address,
           int employeeCount, const std::string& productType, int productionCapacity);
    ~Factory() override;
    void show() const override;
};

#endif // MYCLASS_HPP