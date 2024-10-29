#include "Townhouse.h"

Townhouse::Townhouse() : ResidentialBuilding(4, 30000.00, nullptr, nullptr, nullptr, nullptr) {}

Townhouse::Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(4, 30000.00, water, power, waste, sewage) {}

void Townhouse::displayStatus(){
    std::cout << "Townhouse Status:\n";
    ResidentialBuilding::displayStatus();
}

double Townhouse::getTaxRevenue() {
    return ResidentialBuilding::getTaxRevenue() * 1.2;  // Townhouses generate 20% more revenue
}

std::unique_ptr<ResidentialBuilding> Townhouse::clone() const {
    return std::make_unique<Townhouse>(*this);
}