#ifndef CONCRETETAXCOLLECTOR_H
#define CONCRETETAXCOLLECTOR_H

#include "taxCollector.h"
#include "Government.h"
#include "ZoneComposite.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "NPCManager.h"

/**
 * @class ConcreteTaxCollector
 * @brief A concrete implementation of the taxCollector interface, responsible for collecting taxes from various types of buildings and zones.
 * 
 * The ConcreteTaxCollector class defines specific tax collection behaviors for 
 * residential buildings, commercial buildings, and zones within the city.
 */
class ConcreteTaxCollector : public taxCollector {
public:
    /**
     * @brief Collects tax from a residential building.
     * 
     * Defines the tax collection behavior for residential buildings by accessing 
     * the necessary resources and applying tax rates specific to residential properties.
     * 
     * @param RB Pointer to the ResidentialBuilding from which to collect tax.
     */
    void visit(ResidentialBuilding* RB);

    /**
     * @brief Collects tax from a commercial building.
     * 
     * Defines the tax collection behavior for commercial buildings, taking into 
     * account specific commercial tax rules.
     * 
     * @param CB Pointer to the CommercialBuilding from which to collect tax.
     */
    void visit(CommercialBuilding* CB);

    /**
     * @brief Collects tax from a composite zone.
     * 
     * Defines the tax collection behavior for a zone, which may encompass 
     * multiple buildings of various types.
     * 
     * @param Rzone Pointer to the ZoneComposite from which to collect tax.
     */
    void visit(ZoneComposite* Rzone);
};

#endif
