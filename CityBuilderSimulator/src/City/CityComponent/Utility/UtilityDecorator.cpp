#include "UtilityDecorator.h"

UtilityDecorator::UtilityDecorator(std::unique_ptr<UtilityFlyweight> utility, CityComposite* player)
    : UtilityFlyweight(*utility), wrappedUtility(std::move(utility)), player(player) {
    upgradeCost = cost * 0.2;
    repairCost = cost * 0.1;
}

void UtilityDecorator::connect(double distance) {
    wrappedUtility->connect(distance);
}

std::unique_ptr<UtilityFlyweight> UtilityDecorator::clone() const {
    return std::make_unique<UtilityDecorator>(wrappedUtility->clone(), player);
}

void UtilityDecorator::upgrade() {
    if (player->deductBudget(upgradeCost)) {  // Deduct upgrade cost from player's budget
        level++;
        capacity += 10;
        effectRadius += 3.0;
        resourceConsumption += 5;
        cost += upgradeCost;

        std::cout << name << " upgraded to level " << level
                << ". New capacity: " << capacity
                << ", effect radius: " << effectRadius
                << ", resource consumption: " << resourceConsumption
                << ", next upgrade cost: " << cost * 0.2 << "\n";
    } else {
        std::cout << "Insufficient funds for upgrade.\n";
    }
}

void UtilityDecorator::repair(){
    if (player->deductBudget(repairCost)) {
        isOperational = true;
        std::cout << name << " repaired. Repair cost: " << repairCost << "\n";
    } else {
        std::cout << "Insufficient funds for repair.\n";
    }
}