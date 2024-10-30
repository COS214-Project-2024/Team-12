#include "CityComponent.h"
#include "IndustrialZoneComposite.h"

#include <vector>
#include <iostream>

IndustrialZoneComposite::IndustrialZoneComposite(double taxRate) : industrialTaxRate(taxRate) {}

void IndustrialZoneComposite::add(CityComponent* building){
	 industrialbuildings.push_back(building);
}

void IndustrialZoneComposite::remove(CityComponent* building){
	industrialbuildings.erase(std::remove(industrialbuildings.begin(), industrialbuildings.end(), building), industrialbuildings.end());
}

void IndustrialZoneComposite::displayStatus(){
	std::cout << "Industrial Zone:\n";
        for (auto& building : industrialbuildings) {
            building->displayStatus();
        }
}

/* double IndustrialZoneComposite::getTaxRevenue(){
	double totalTax = 0;
    for (auto& building : industrialbuildings) {
        totalTax += industrialTaxRate; // Simplified; this could depend on building specifics
    }
    return totalTax;
} */