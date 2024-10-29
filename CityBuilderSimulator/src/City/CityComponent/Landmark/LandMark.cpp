#include "LandMark.h"

LandMark::LandMark(const std::string& type, int  capacity,double price,
                        std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : landMarkType(type), visitorCapacity(capacity), price(price),
        waterSupply(std::move(water)), powerSupply(std::move(power)), wasteManagement(std::move(waste)), sewageManagement(std::move(sewage)) {}

void LandMark::displayStatus() {
        std::cout << "LandMark Status:\n"
                << "Type of landmark: " << landMarkType << "\n"
                << " Visitor Capacity: "<<visitorCapacity<<"\n"
                << "Price: $" << price << "\n";
                

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



void LandMark::connectWater(std::shared_ptr<UtilityFlyweight> water) { waterSupply = std::move(water); }
void LandMark::connectPower(std::shared_ptr<UtilityFlyweight> power) { powerSupply = std::move(power); }
void LandMark::connectWasteManagement(std::shared_ptr<UtilityFlyweight> waste) { wasteManagement = std::move(waste); }
void LandMark::connectSewage(std::shared_ptr<UtilityFlyweight> sewage) { sewageManagement = std::move(sewage); }

void LandMark::applyUtilityConsumption() {
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