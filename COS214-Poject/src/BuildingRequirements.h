#ifndef BUILDING_REQUIREMENTS_H
#define BUILDING_REQUIREMENTS_H

#include <map>
#include <string>
#include <iostream>

/**
 * @struct ResourceRequirement
 * @brief Defines the resource requirements for constructing a building.
 * 
 * This struct holds the amount of each resource (wood, stone, steel, concrete) 
 * needed to construct a specific type of building.
 */
struct ResourceRequirement {
    int wood;     /**< Amount of wood required */
    int stone;    /**< Amount of stone required */
    int steel;    /**< Amount of steel required */
    int concrete; /**< Amount of concrete required */

    /**
     * @brief Constructor to initialize resource requirements.
     * 
     * @param w Amount of wood required (default: 0).
     * @param st Amount of stone required (default: 0).
     * @param se Amount of steel required (default: 0).
     * @param c Amount of concrete required (default: 0).
     */
    ResourceRequirement(int w = 0, int st = 0, int se = 0, int c = 0)
        : wood(w), stone(st), steel(se), concrete(c) {}
};

/**
 * @var buildingResourceRequirements
 * @brief A map that associates building types with their respective resource requirements.
 * 
 * This map contains entries for various types of buildings (residential, commercial, and industrial)
 * and their corresponding resource requirements for construction.
 */
const std::map<std::string, ResourceRequirement> buildingResourceRequirements {
    // Residential Buildings
    {"House", ResourceRequirement(10, 5, 0, 0)},
    {"Flat", ResourceRequirement(15, 10, 5, 5)},
    {"Townhouse", ResourceRequirement(20, 15, 10, 10)},
    {"Estate", ResourceRequirement(25, 20, 15, 15)},
    
    // Commercial Buildings
    {"Shop", ResourceRequirement(15, 10, 10, 10)},
    {"Mall", ResourceRequirement(30, 25, 20, 20)},
    {"Office", ResourceRequirement(25, 20, 25, 25)},
    
    // Industrial Buildings
    {"MetalWorkFacility", ResourceRequirement(20, 30, 40, 20)},
    {"PetroChemical", ResourceRequirement(15, 25, 35, 40)},
    {"CrystalCraft", ResourceRequirement(20, 40, 30, 25)},
    {"WoodAndCoal", ResourceRequirement(40, 30, 25, 20)}
};

/**
 * @brief Initializes the collected resources map with zero values.
 * 
 * This function populates the given map with resource types as keys 
 * and initializes their values to zero.
 * 
 * @param collectedResources A map to hold the quantities of collected resources.
 */
inline void initializeCollectedResources(std::map<std::string, int>& collectedResources) {
    collectedResources["Wood"] = 0;
    collectedResources["Stone"] = 0;
    collectedResources["Steel"] = 0;
    collectedResources["Concrete"] = 0;
}

/**
 * @brief Checks if the collected resources meet the requirements for a specified building.
 * 
 * This function compares collected resource quantities against the requirements for a given building type.
 * Optionally, it displays information about the requirements and current resource levels.
 * 
 * @param buildingType The type of building to check resources for.
 * @param collectedResources A map containing the currently collected resource quantities.
 * @param displayInfo Flag to control the display of requirement information (default: true).
 * @return true if resources meet or exceed the requirements; false otherwise.
 */
inline bool checkResourceRequirements(const std::string& buildingType, 
                                    const std::map<std::string, int>& collectedResources,
                                    bool displayInfo = true) {
    auto it = buildingResourceRequirements.find(buildingType);
    if (it == buildingResourceRequirements.end()) {
        if (displayInfo) {
            std::cout << "\033[1;31mError: Building type '" << buildingType << "' not found in requirements!\033[0m\n";
        }
        return false;
    }

    const auto& req = it->second;
    
    if (displayInfo) {
        std::cout << "\n=== Resource Requirements for " << buildingType << " ===\n";
        std::cout << "Required / Available:\n";
        std::cout << "Wood: " << req.wood << " / " << collectedResources.at("Wood") << "\n";
        std::cout << "Stone: " << req.stone << " / " << collectedResources.at("Stone") << "\n";
        std::cout << "Steel: " << req.steel << " / " << collectedResources.at("Steel") << "\n";
        std::cout << "Concrete: " << req.concrete << " / " << collectedResources.at("Concrete") << "\n";
    }

    bool sufficient = true;
    
    if (collectedResources.at("Wood") < req.wood) sufficient = false;
    if (collectedResources.at("Stone") < req.stone) sufficient = false;
    if (collectedResources.at("Steel") < req.steel) sufficient = false;
    if (collectedResources.at("Concrete") < req.concrete) sufficient = false;

    if (displayInfo && !sufficient) {
        std::cout << "\033[1;31mInsufficient resources!\033[0m\n";
    }

    return sufficient;
}

#endif
