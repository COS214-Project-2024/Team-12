// taxCollector.h
#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H

#include "Government.h"

// Forward declarations
class ResidentialBuilding;
class CommercialBuilding;
class ZoneComposite;

class taxCollector {
public:
    taxCollector() {} // Now we don't need to store Government pointer
    virtual ~taxCollector() = default;

    virtual void visit(ResidentialBuilding* RB) = 0;
    virtual void visit(CommercialBuilding* CB) = 0;
    virtual void visit(ZoneComposite* Rzone) = 0;

protected:
    // Helper method to access the singleton
    Government& getGovernment() {
        return Government::getInstance();
    }
};

#endif