#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "UtilityFlyweight.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "WaterSupply.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <stdexcept>

class UtilityFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<UtilityFlyweight>> flyweights;

public:
    // Get utility by string name (for backward compatibility)
    std::shared_ptr<UtilityFlyweight> getUtility(const std::string& type);

    // Get utility by numeric type (for menu selection)
    std::shared_ptr<UtilityFlyweight> getUtilityByType(int type);

    // Static method to get utility names
    static std::string getUtilityName(int type);

    // Static method to get utility cost
    static double getUtilityCost(int type);
};

#endif
