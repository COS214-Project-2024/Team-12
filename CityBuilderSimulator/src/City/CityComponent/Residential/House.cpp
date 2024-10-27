#include "House.h"

House::House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding("Good", 3, 15000.0, 200.00, water, power, waste, sewage) {}

void House::displayStatus() {
    std::cout << "House Status:\n";
    ResidentialBuilding::displayStatus();
}

double House::getTaxRevenue() {
     return ResidentialBuilding::getTaxRevenue() * 1.1;  // Houses generate 10% more revenue
}

std::unique_ptr<ResidentialBuilding> House::clone() const{
    return std::make_unique<House>(*this);
}