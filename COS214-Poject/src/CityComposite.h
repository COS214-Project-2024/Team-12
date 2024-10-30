#ifndef CITY_COMPOSITE_H
#define CITY_COMPOSITE_H

#include "CityComponent.h"
#include "Government.h"
#include "taxCollector.h"
#include <string>
#include <vector>
#include <algorithm>

class CityComposite : public CityComponent {
private:
    std::vector<CityComponent*> zones; // Collection of zones
    std::string cityName;
    double budget;

public:
    CityComposite(const std::string& name);
    ~CityComposite();

    void add(CityComponent* zone) override;

    void remove(CityComponent* zone) override;

    void displayStatus() override;

   
    double getBudget() const;

    bool deductBudget(double amount);

    // Add to the initial city budget
    void addBudget(double amount);

    bool checkCityConditions();


    std::string getBuildingType() override{
        return "City";
    }

    void accept(taxCollector* tax) override{
        //can't collect tax from the city
    }

};

#endif