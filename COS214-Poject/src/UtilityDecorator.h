// #ifndef UTILITY_DECORATOR_H
// #define UTILITY_DECORATOR_H

// #include "UtilityFlyweight.h"
// #include "CityComposite.h"
// #include <memory>

// class UtilityDecorator : public UtilityFlyweight {
// protected:
//     std::shared_ptr<UtilityFlyweight> wrappedUtility;
//     double upgradeCost;     // Cost to upgrade
//     double repairCost;      // Cost to repair
//     CityComposite* player;  // to access budget in city composite
// public:
//     UtilityDecorator(std::shared_ptr<UtilityFlyweight> utility, CityComposite* player);
//     void connect(double distance);
//     std::shared_ptr<UtilityFlyweight> clone() const;
//     void upgrade();
//     virtual void repair();
//     virtual double getUpgradeCost() const;
//     virtual int getResourceConsumption() const;
//     int getLevel() const;
// };

// #endif