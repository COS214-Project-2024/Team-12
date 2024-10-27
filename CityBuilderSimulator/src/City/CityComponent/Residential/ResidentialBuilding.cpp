#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding(const std::string& condition, int bedrooms, double price, double maintenanceCost,
                        std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power, 
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : condition(condition), bedrooms(bedrooms), price(price), maintenanceCost(maintenanceCost), taxPaid(false),
        waterSupply(std::move(water)), powerSupply(std::move(power)), wasteManagement(std::move(waste)), sewageManagement(std::move(sewage)) {}

void ResidentialBuilding::displayStatus() {
        std::cout << "Residential Building Status:\n"
                << "Condition: " << condition << "\n"
                << "Bedrooms: " << bedrooms << "\n"
                << "Price: $" << price << "\n"
                << "Maintenance Cost: $" << maintenanceCost << "\n"
                << "Tax Paid: " << (taxPaid ? "Yes" : "No") << "\n";

        // Display status of each connected utility
        if (waterSupply) {
                std::cout << "Water Supply Status:\n";
                waterSupply->displayStatus();
        }
        if (powerSupply) {
                std::cout << "Power Supply Status:\n";
                powerSupply->displayStatus();
        }
        if (wasteManagement) {
                std::cout << "Waste Management Status:\n";
                wasteManagement->displayStatus();
        }
        if (sewageManagement) {
                std::cout << "Sewage Management Status:\n";
                sewageManagement->displayStatus();
        }
}

double ResidentialBuilding::getTaxRevenue() {
        double conditionMultiplier = (condition == "Good") ? 1.5 : 1.0;
        double baseRevenue = price * 0.02; // 2% of price as base tax revenue
        return baseRevenue * conditionMultiplier;
}

void ResidentialBuilding::connectWater(std::shared_ptr<UtilityFlyweight> water) { waterSupply = std::move(water); }
void ResidentialBuilding::connectPower(std::shared_ptr<UtilityFlyweight> power) { powerSupply = std::move(power); }
void ResidentialBuilding::connectWasteManagement(std::shared_ptr<UtilityFlyweight> waste) { wasteManagement = std::move(waste); }
void ResidentialBuilding::connectSewage(std::shared_ptr<UtilityFlyweight> sewage) { sewageManagement = std::move(sewage); }

void ResidentialBuilding::applyUtilityConsumption() {
        if (waterSupply && waterSupply->getOperationalStatus()) {
                std::cout << "Consuming water resources: " << waterSupply->getResourceConsumption() << "\n";
        }
        if (powerSupply && powerSupply->getOperationalStatus()) {
                std::cout << "Consuming power resources: " << powerSupply->getResourceConsumption() << "\n";
        }
        if (wasteManagement && wasteManagement->getOperationalStatus()) {
                std::cout << "Waste management resources consumed: " << wasteManagement->getResourceConsumption() << "\n";
        }
        if (sewageManagement && sewageManagement->getOperationalStatus()) {
                std::cout << "Sewage management resources consumed: " << sewageManagement->getResourceConsumption() << "\n";
        }
}

void ResidentialBuilding::repairBuilding() {
        if (condition == "Worn Out") {
                condition = "Good";
                std::cout << "Building repaired to 'Good' condition at cost of R" << maintenanceCost << "\n";
        } else {
                std::cout << "Building is already in 'Good' condition. No repairs needed.\n";
        }
}