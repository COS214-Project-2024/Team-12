#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "../src/City/CityComponent/Utility/UtilityFlyweight.h"
#include "../src/City/CityComponent/Utility/PowerPlant.h"
#include "../src/City/CityComponent/Utility/SewageSystem.h"
#include "../src/City/CityComponent/Utility/WasteManagement.h"
#include "../src/City/CityComponent/Utility/WaterSupply.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <stdexcept>

class UtilityFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<UtilityFlyweight>> flyweights;

public:
    std::shared_ptr<UtilityFlyweight> getUtility(const std::string& type);
};

#endif
