#include "Estate.h"

Estate::Estate() : ResidentialBuilding(6, 50000.00, nullptr, nullptr, nullptr, nullptr) {}

Estate::Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(6, 50000.00, water, power, waste, sewage) {}

void Estate::displayStatus(){
    std::cout << "Estate Status:\n";
    ResidentialBuilding::displayStatus();
}



std::unique_ptr<ResidentialBuilding> Estate::clone() const {
    return std::make_unique<Estate>(*this);
}