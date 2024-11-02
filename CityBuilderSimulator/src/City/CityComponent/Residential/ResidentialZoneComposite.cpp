#include "../CityComponent.h"
#include "ResidentialZoneComposite.h"
#include "CollectTaxResidential.h"

#include <vector>
#include <iostream>

ResidentialZoneComposite::ResidentialZoneComposite(double taxRate, CollectTaxResidential& sarsR) : residentialTaxRate(taxRate),sars(sarsR) {}
    

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
        
        // Check if component is a ResidentialBuilding
        ResidentialBuilding* residentialBuilding = dynamic_cast<ResidentialBuilding*>(component);
        if (residentialBuilding != nullptr) {  // dynamic_cast was successful
            residentialBuilding->accept(sars);
        }
    }

}

