#ifndef BUILDING_REQUIREMENTS_H
#define BUILDING_REQUIREMENTS_H

#include <map>
#include <string>
#include <iostream>

struct ResourceRequirement {
    int wood;
    int stone;
    int steel;
    int concrete;

    ResourceRequirement(int w = 0, int st = 0, int se = 0, int c = 0)
        : wood(w), stone(st), steel(se), concrete(c) {}
};

// Initialize the map with proper resource requirements
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

// Add helper functions for resource management
inline void initializeCollectedResources(std::map<std::string, int>& collectedResources) {
    collectedResources["Wood"] = 0;
    collectedResources["Stone"] = 0;
    collectedResources["Steel"] = 0;
    collectedResources["Concrete"] = 0;
}

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