// #include "AdvancedTechnologyDecorator.h"

// AdvancedTechnologyDecorator::AdvancedTechnologyDecorator(std::shared_ptr<UtilityFlyweight> utility, CityComposite* player)
//     : UtilityDecorator(std::move(utility), player) {}

// void AdvancedTechnologyDecorator::upgrade(){
//     UtilityDecorator::upgrade();
//     if (level >= 4) {  // Apply advanced tech benefits at level 4 and beyond
//         cost -= 500;
//         std::cout << name << " upgraded with advanced technology! Operating cost reduced to: "
//             << cost << "\n";
//     }
// }