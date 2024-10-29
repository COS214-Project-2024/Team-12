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

/* double CommercialZoneComposite::getTaxRevenue(){
	double totalTax = 0;
    for (auto& building : commercialbuildings) {
        totalTax += commercialTaxRate; // Simplified; this could depend on building specifics
    }
    return totalTax;
} */