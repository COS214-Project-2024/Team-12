#include "PublicService.h"
#include <iostream>

/**
 * @brief Constructor for the PublicService class.
 * 
 * Initializes the public service with the specified utility connections.
 * 
 * @param water A shared pointer to the water utility.
 * @param power A shared pointer to the power utility.
 * @param waste A shared pointer to the waste management utility.
 * @param sewage A shared pointer to the sewage management utility.
 */
PublicService::PublicService(std::shared_ptr<UtilityFlyweight> water, 
                             std::shared_ptr<UtilityFlyweight> power,
                             std::shared_ptr<UtilityFlyweight> waste, 
                             std::shared_ptr<UtilityFlyweight> sewage)
    : waterSupply(water), powerSupply(power), wasteManagement(waste), sewageManagement(sewage) {}

/**
 * @brief Displays the status of the public service building.
 * 
 * This function prints the building type and whether it has all necessary
 * utilities connected. The function is currently commented out.
 */
// void PublicService::displayStatus() {
//     std::cout << "Building Type: " << getBuildingType() << "\n"
//               << "Utilities Connected: " << (hasUtilities() ? "Yes" : "No") << "\n";
// }
