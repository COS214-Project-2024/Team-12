#include "GreenTechnologyDecorator.h"

GreenTechnologyDecorator::GreenTechnologyDecorator(std::unique_ptr<UtilityFlyweight> utility, CityComposite *player)
    : UtilityDecorator(std::move(utility), player) {}

void GreenTechnologyDecorator::upgrade() {
    UtilityDecorator::upgrade();
    if (level >= 4) {
        resourceConsumption -= 5;
        std::cout << name << " now uses green technology! Reduced resource consumption: "
        << resourceConsumption << "\n";
    }
}