#include "LandMark.h"

/**
 * @brief Constructs a LandMark with specified type, capacity, price, and utilities.
 * 
 * @param type The type of the landmark (e.g., historical, recreational)
 * @param capacity Maximum visitor capacity of the landmark
 * @param price Cost or entry price for the landmark
 * @param water Shared pointer to the water supply utility
 * @param power Shared pointer to the power supply utility
 * @param waste Shared pointer to the waste management utility
 * @param sewage Shared pointer to the sewage management utility
 */
LandMark::LandMark(const std::string& type, int capacity, double price,
                   std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                   std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : landMarkType(type), visitorCapacity(capacity), price(price),
          waterSupply(std::move(water)), powerSupply(std::move(power)), 
          wasteManagement(std::move(waste)), sewageManagement(std::move(sewage)) {}

/**
 * @brief Displays the status of the landmark, including type, capacity, price, and utility statuses.
 * 
 * This function outputs the current status of the landmark, showing its type, visitor capacity, and price.
 * It also displays the status of each connected utility (water, power, waste management, and sewage).
 */
void LandMark::displayStatus() {
    std::cout << "LandMark Status:\n"
              << "Type of landmark: " << landMarkType << "\n"
              << "Visitor Capacity: " << visitorCapacity << "\n"
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
