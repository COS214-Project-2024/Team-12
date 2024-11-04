#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H

#include "Government.h"

// Forward declarations
class ResidentialBuilding;
class CommercialBuilding;
class ZoneComposite;

/**
 * @class taxCollector
 * @brief Abstract class representing a tax collector that visits various building types to collect taxes.
 * 
 * The `taxCollector` class defines an interface for visiting different types of buildings
 * and zones in the city to collect taxes. Each specific type of building or zone has its
 * own `visit` method. The class also provides access to the `Government` singleton, which
 * allows interaction with central government functions or resources.
 */
class taxCollector {
public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the taxCollector without needing to store a pointer to the `Government` instance.
     */
    taxCollector() {} 

    /**
     * @brief Virtual destructor.
     * 
     * Allows derived classes to clean up resources properly.
     */
    virtual ~taxCollector() = default;

    /**
     * @brief Visit a residential building to collect taxes.
     * 
     * @param RB A pointer to the residential building.
     */
    virtual void visit(ResidentialBuilding* RB) = 0;

    /**
     * @brief Visit a commercial building to collect taxes.
     * 
     * @param CB A pointer to the commercial building.
     */
    virtual void visit(CommercialBuilding* CB) = 0;

    /**
     * @brief Visit a residential zone composite to collect taxes.
     * 
     * @param Rzone A pointer to the residential zone composite.
     */
    virtual void visit(ZoneComposite* Rzone) = 0;

protected:
    /**
     * @brief Provides access to the `Government` singleton instance.
     * 
     * @return A reference to the `Government` singleton.
     */
    Government& getGovernment() {
        return Government::getInstance();
    }
};

#endif
