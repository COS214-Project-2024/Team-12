#include "../CityComponent.h"
#include "CommercialZoneComposite.h"

#include <vector>
#include <iostream>

CommercialZoneComposite::CommercialZoneComposite(double taxRate) : commercialTaxRate(taxRate) {}

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

