#include "GreenTechnologyDecorator.h"

GreenTechnologyDecorator::GreenTechnologyDecorator(std::shared_ptr<UtilityFlyweight> utility, CityComposite *player)
    : UtilityDecorator(std::move(utility), player) {}

// void GreenTechnologyDecorator::upgrade() {
//     UtilityDecorator::upgrade();  // Call base upgrade

//     if (wrappedUtility->getLevel() >= 4) {
//         // Calculate reduced consumption
//         int baseConsumption = UtilityDecorator::getResourceConsumption();
//         int reducedConsumption = static_cast<int>(baseConsumption * 0.6);  // 40% reduction
        
//         // Set the reduced consumption
//         this->resourceConsumption = reducedConsumption;
        
//         std::cout << getName() << " now uses green technology! Reduced resource consumption from "
//                 << baseConsumption << " to " << reducedConsumption << std::endl;
//     }
// }

void GreenTechnologyDecorator::upgrade() {
    // Store the pre-upgrade consumption
    int previousConsumption = resourceConsumption;
    
    // Do the normal upgrade
    UtilityDecorator::upgrade();
    
    // After level 4, apply green tech reduction
    if (level >= 4) {
        resourceConsumption = static_cast<int>(resourceConsumption * 0.6);  // 40% reduction
        std::cout << getName() << " now uses green technology! Reduced consumption from "
                  << previousConsumption << " to " << resourceConsumption << std::endl;
    }
}

int GreenTechnologyDecorator::getResourceConsumption() const {
    int baseConsumption = UtilityDecorator::getResourceConsumption();
    if (level >= 4) {
        return static_cast<int>(baseConsumption * 0.6);  // 40% reduction
    }
    return baseConsumption;
}

double GreenTechnologyDecorator::getUpgradeCost() const {
    return upgradeCost;
}