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

class CityComposite : public CityComponent {
private:
    std::vector<CityComponent*> zones; // Collection of zones
    std::string cityName;
    MapGrid* map;
    double budget;

public:
    CityComposite(const std::string& name, MapGrid* cityMap);
    ~CityComposite();

    void add(CityComponent* zone, int x, int y) override;

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
        // //can't collect tax from the city
        // for(auto& zone : zones){
        //     zone->accept(tax);
        // }
    }

    void connectZones(CityComponent* zoneA, CityComponent* zoneB, std::unique_ptr<Transport> transport);

};

#endif