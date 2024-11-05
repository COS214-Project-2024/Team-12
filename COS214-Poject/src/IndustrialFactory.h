#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include <memory>
#include "Industry.h"

/**
 * @brief Abstract factory class for creating industrial facilities.
 * 
 * The IndustrialFactory class serves as a base class for factories that create 
 * different types of industrial facilities in the city. It provides an interface 
 * for creating industrial instances, supporting extensions for various industrial 
 * types and customization.
 */
class IndustrialFactory {
public:
    /**
     * @brief Virtual destructor for IndustrialFactory.
     * 
     * Ensures proper cleanup for derived classes when deleting through 
     * a pointer to IndustrialFactory.
     */
    virtual ~IndustrialFactory() {};

    // Uncomment and implement the following line in derived classes:
    // virtual std::unique_ptr<Industrial> createIndustry() = 0;
};

#endif
