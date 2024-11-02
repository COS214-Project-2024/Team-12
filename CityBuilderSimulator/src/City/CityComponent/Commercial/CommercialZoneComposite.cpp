#include "../CityComponent.h"
#include "CommercialZoneComposite.h"

#include <vector>
#include <iostream>

CommercialZoneComposite::CommercialZoneComposite(double taxRate, CollectTaxCommercial& sarsR) : commercialTaxRate(taxRate), sars(sarsR) {}

void CommercialZoneComposite::add(CityComponent* building){
	 commercialbuildings.push_back(building);
}

void CommercialZoneComposite::remove(CityComponent* building){
	commercialbuildings.erase(std::remove(commercialbuildings.begin(), commercialbuildings.end(), building), commercialbuildings.end());
}

void CommercialZoneComposite::displayStatus(){
	std::cout << "Industrial Zone:\n";
        for (auto& building : commercialbuildings) {
            building->displayStatus();
        }
}

void CommercialZoneComposite::payTax(){
    std::vector<CityComponent*>::iterator it;
    for (it = commercialbuildings.begin(); it != commercialbuildings.end(); ++it) {
        CityComponent* component = *it;
        // Check if component is a CommercialBuilding
        CommercialBuilding* commercialBuilding = dynamic_cast<CommercialBuilding*>(component);
        if (commercialBuilding != nullptr) {  // dynamic_cast was successful
            commercialBuilding->accept(sars);
        }
    }

}

