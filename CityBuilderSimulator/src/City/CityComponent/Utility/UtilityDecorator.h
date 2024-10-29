#ifndef UTILITY_DECORATOR_H
#define UTILITY_DECORATOR_H

#include "../src/City/CityComponent/Utility/UtilityFlyweight.h"
#include "../src/City/CityComponent/CityComposite/CityComposite.h"
#include <memory>

class UtilityDecorator : public UtilityFlyweight {
protected:
    std::unique_ptr<UtilityFlyweight> wrappedUtility;
    double upgradeCost;     // Cost to upgrade
    double repairCost;      // Cost to repair
    CityComposite* player;  // to access budget in city composite
public:
    UtilityDecorator(std::unique_ptr<UtilityFlyweight> utility, CityComposite* player);
    void connect(double distance);
    std::unique_ptr<UtilityFlyweight> clone() const;
    void upgrade();
    void repair();
    double getUpgradeCost() const;
};

#endif