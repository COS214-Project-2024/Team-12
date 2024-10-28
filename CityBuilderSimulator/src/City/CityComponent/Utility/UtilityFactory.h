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
    std::shared_ptr<UtilityFlyweight> getUtility(const std::string& type);
};

#endif
