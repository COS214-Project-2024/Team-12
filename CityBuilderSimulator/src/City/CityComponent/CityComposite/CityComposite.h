#ifndef CITY_COMPOSITE_H
#define CITY_COMPOSITE_H

#include "../CityComponent.h"
#include <string>
#include <vector>

class CityComposite : public CityComponent {
private:
    std::vector<CityComponent*> zones; // Collection of zones
    std::string cityName;
    double budget;

public:
    CityComposite(const std::string& name);

    void add(CityComponent* zone) override;

    void remove(CityComponent* zone) override;

    void displayStatus() override;

    double getTaxRevenue() override;

    double getBudget() const;

    bool deductBudget(double amount);

    // Add to the initial city budget
    void addBudget(double amount);
};

#endif