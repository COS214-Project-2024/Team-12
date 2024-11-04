#ifndef CITY_COMPOSITE_H
#define CITY_COMPOSITE_H

#include "CityComponent.h"
#include "Transport.h"
#include "Government.h"
#include "taxCollector.h"
#include "MapGrid.h"
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class CityComposite : public CityComponent {
private:
    std::vector<std::shared_ptr<CityComponent>> zones; // Collection of zones
    std::string cityName;

public:
    CityComposite(const std::string& name);
    ~CityComposite();

    void add(std::shared_ptr<CityComponent> component) override;

    void remove(std::shared_ptr<CityComponent> component) override;

    void displayStatus() override;

   
    /* double getBudget() const;

    bool deductBudget(double amount);

    // Add to the initial city budget
    void addBudget(double amount); */

    bool checkCityConditions();


    std::string getBuildingType() const override{
        return "City";
    }

    void accept(taxCollector* tax) override{
        // can't collect tax from the city
        // for(auto& zone : zones){
        //     zone->accept(tax);
        // }
    }

    void connectZones(CityComponent* zoneA, CityComponent* zoneB, std::unique_ptr<Transport> transport);

    void updateHappinessForNewComponent(const std::shared_ptr<CityComponent>& component);

    void adjustHappinessBasedOnTaxRate();

};

#endif