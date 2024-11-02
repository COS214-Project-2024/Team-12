#include "GreenTechnologyDecorator.h"

GreenTechnologyDecorator::GreenTechnologyDecorator(std::unique_ptr<UtilityFlyweight> utility, CityComposite *player)
    : UtilityDecorator(std::move(utility), player) {}

void GreenTechnologyDecorator::upgrade() {
    if (player->getBudget() < upgradeCost) {
        std::cout << "Insufficient funds for upgrade.\n";
        return;
    }

    UtilityDecorator::upgrade();
    if (getLevel() >= 4) {
        resourceConsumption -= 5;
        std::cout << getName() << " now uses green technology! Reduced resource consumption: "
        << resourceConsumption << "\n";
    }
}