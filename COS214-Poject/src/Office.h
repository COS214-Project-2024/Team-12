#ifndef OFFICE_H
#define OFFICE_H

#include <string>
#include "CommercialBuilding.h"

/**
 * @class Office
 * @brief Represents an office building, a type of commercial building with utility connections.
 */
class Office : public CommercialBuilding {
public:
    /**
     * @brief Default constructor for Office.
     * 
     * Initializes an Office building with a base capacity of 600.0 and no connected utilities.
     */
    Office();

    /**
     * @brief Constructs an Office with specified utility connections.
     * 
     * Initializes an Office building with a base capacity of 600.0 and connects to 
     * the specified water, power, waste, and sewage utilities.
     * 
     * @param water Shared pointer to the water utility.
     * @param power Shared pointer to the power utility.
     * @param waste Shared pointer to the waste utility.
     * @param sewage Shared pointer to the sewage utility.
     */
    Office(std::shared_ptr<UtilityFlyweight> water,
           std::shared_ptr<UtilityFlyweight> power,
           std::shared_ptr<UtilityFlyweight> waste,
           std::shared_ptr<UtilityFlyweight> sewage);
    
    /**
     * @brief Gets the display symbol for the Office.
     * 
     * @return Character symbol representing the Office ('O').
     */
    char getDisplaySymbol() const { return 'O'; }

    /**
     * @brief Gets the building type.
     * 
     * @return A string representing the building type ("Office").
     */
    std::string getBuildingType() const override { return "Office"; }
};

#endif
