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