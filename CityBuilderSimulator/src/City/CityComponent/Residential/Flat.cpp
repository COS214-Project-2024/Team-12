#include "Flat.h"

Flat::Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(2, 10000.00, water, power, waste, sewage) {}

void Flat::displayStatus(){
    std::cout << "Flat Status:\n";
    ResidentialBuilding::displayStatus();
}



std::unique_ptr<ResidentialBuilding> Flat::clone() const {
        return std::make_unique<Flat>(*this);
}