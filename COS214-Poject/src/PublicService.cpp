#include "PublicService.h"
#include <iostream>


PublicService::PublicService(std::shared_ptr<UtilityFlyweight> water, 
                             std::shared_ptr<UtilityFlyweight> power,
                             std::shared_ptr<UtilityFlyweight> waste, 
                             std::shared_ptr<UtilityFlyweight> sewage)
    : waterSupply(water), powerSupply(power), wasteManagement(waste), sewageManagement(sewage) {}


// void PublicService::displayStatus() {
//         std::cout << "Building Type: " << getBuildingType() << "\n"
//                 << "Utilities Connected: " << (hasUtilities() ? "Yes" : "No") << "\n";
// }


