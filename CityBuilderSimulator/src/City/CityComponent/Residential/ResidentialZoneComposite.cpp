#include "../CityComponent.h"
#include "ResidentialZoneComposite.h"

#include <vector>
#include <iostream>

ResidentialZoneComposite::ResidentialZoneComposite(double taxRate) : residentialTaxRate(taxRate) {}

void ResidentialZoneComposite::add(CityComponent* building){
	 buildings.push_back(building);
}

void ResidentialZoneComposite::remove(CityComponent* building){
	buildings.erase(std::remove(buildings.begin(), buildings.end(), building), buildings.end());
}

void ResidentialZoneComposite::displayStatus(){
	std::cout << "Residential Zone:\n";
        for (auto& building : buildings) {
            building->displayStatus();
        }
}


void ResidentialZoneComposite::payTax(){
    std::vector<CityComponent*>::iterator it;
    for (it = buildings.begin(); it != buildings.end(); ++it) {
        CityComponent* component = *it;
        component->accept(sars);
    }

}

void ResidentialZoneComposite::accept(taxCollector* TC){
    TC->visit(this);
}
  