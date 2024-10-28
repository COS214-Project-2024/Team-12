#ifndef MOCKCITYCOMPOSITE_H
#define MOCKCITYCOMPOSITE_H

#include "CityComponent/CityComposite/CityComposite.h"

class MockCityComposite : public CityComposite {
private:
    double budget;
public:
    explicit MockCityComposite(const std::string& name, double initialBudget);
    bool deductBudget(double amount);
    double getBudget() const;
    void addBudget(double amount);
    void setBudget(double amount);
};

#endif