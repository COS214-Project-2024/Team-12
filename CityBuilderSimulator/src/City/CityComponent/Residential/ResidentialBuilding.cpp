#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding(int bedrooms, double price,
                        std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : bedrooms(bedrooms), price(price), taxPayed(false),
        waterSupply(std::move(water)), powerSupply(std::move(power)), wasteManagement(std::move(waste)), sewageManagement(std::move(sewage)) {}

void ResidentialBuilding::displayStatus() {
        std::cout << "Residential Building Status:\n"
                << "Bedrooms: " << bedrooms << "\n"
                << "Price: $" << price << "\n"
                << "Tax Paid: " << (taxPayed ? "Yes" : "No") << "\n";

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

bool ResidentialBuilding::hasGreenTechnology() const {
    // Check each utility for GreenTechnologyDecorator presence
    return (dynamic_cast<GreenTechnologyDecorator*>(waterSupply.get()) != nullptr ||
            dynamic_cast<GreenTechnologyDecorator*>(powerSupply.get()) != nullptr ||
            dynamic_cast<GreenTechnologyDecorator*>(wasteManagement.get()) != nullptr ||
            dynamic_cast<GreenTechnologyDecorator*>(sewageManagement.get()) != nullptr);
}
