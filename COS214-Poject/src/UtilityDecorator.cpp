#include "UtilityDecorator.h"

UtilityDecorator::UtilityDecorator(std::shared_ptr<UtilityFlyweight> utility, CityComposite* player)
    : UtilityFlyweight(*utility), wrappedUtility(std::move(utility)), player(player) {
    // Initialize costs
    upgradeCost = cost * 0.2;
    repairCost = cost * 0.1;
}

void UtilityDecorator::connect(double distance) {
    wrappedUtility->connect(distance);
    isOperational = (distance <= effectRadius);
}

std::shared_ptr<UtilityFlyweight> UtilityDecorator::clone() const {
    return std::make_shared<UtilityDecorator>(wrappedUtility->clone(), player);
}

void UtilityDecorator::upgrade() {
    // Calculate upgrade cost first
    double currentUpgradeCost = upgradeCost;

    // Check if player has enough budget and attempt to deduct
    if (player->getBudget() >= currentUpgradeCost && player->deductBudget(currentUpgradeCost)) {
        // Increment level
        level++;
        
        // Update capacity
        capacity += 10;
        
        // Update effect radius
        effectRadius += 3.0;
        
        // Update resource consumption
        resourceConsumption += 5;
        
        // Update cost and calculate new upgrade cost
        cost += currentUpgradeCost;
        upgradeCost = cost * 0.2;

        std::cout << name << " upgraded to level " << level
                << ". New capacity: " << capacity
                << ", effect radius: " << effectRadius
                << ", resource consumption: " << resourceConsumption
                << ", next upgrade cost: " << upgradeCost << "\n";
    } else {
        std::cout << "Insufficient budget.\n";
        std::cout << "Insufficient funds for upgrade.\n";
    }
}

void UtilityDecorator::repair() {
    // Only attempt repair if the utility is not operational
    if (!isOperational) {
        // Calculate repair cost
        double currentRepairCost = repairCost;

        // Check if player has enough budget and attempt to deduct
        if (player->getBudget() >= currentRepairCost && player->deductBudget(currentRepairCost)) {
            // Set operational status to true for both decorator and wrapped utility
            isOperational = true;
            wrappedUtility->activate();
            
            std::cout << name << " repaired. Repair cost: " << currentRepairCost << "\n";
        } else {
            std::cout << "Insufficient budget.\n";
            std::cout << "Insufficient funds for repair.\n";
        }
    }
}

double UtilityDecorator::getUpgradeCost() const {
    return upgradeCost;
}

int UtilityDecorator::getResourceConsumption() const {
    return wrappedUtility->getResourceConsumption();
}

int UtilityDecorator::getLevel() const {
    return wrappedUtility->getLevel();
}