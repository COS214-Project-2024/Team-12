#ifndef INCOMERESOURCEPROCESSOR_H
#define INCOMERESOURCEPROCESSOR_H

#include "ResourceProcessor.h"
#include "IncomeResourceProduct.h"
#include "Government.h"
#include <memory>

/**
 * @class IncomeResourceProcessor
 * @brief Processes and manages storage for income-generating resources.
 * 
 * The IncomeResourceProcessor class handles storing and processing resources 
 * that generate income. It maintains a current storage level and a maximum 
 * storage capacity. The processed resources contribute their market value to 
 * the Government instance.
 */
class IncomeResourceProcessor : public ResourceProcessor {
private:
    std::shared_ptr<IncomeResourceProduct> resource; ///< Pointer to the resource being processed.
    int currentStorage; ///< Current amount of resource in storage.
    const int maxStorage; ///< Maximum storage capacity for the resource.

public:
    /**
     * @brief Constructs an IncomeResourceProcessor with a given resource and optional storage limit.
     * 
     * @param res Shared pointer to an IncomeResourceProduct to be processed.
     * @param maxStorage Maximum storage capacity for the resource (default is 200).
     */
    IncomeResourceProcessor(std::shared_ptr<IncomeResourceProduct> res, int maxStorage = 200);

    /**
     * @brief Processes a specified amount of the resource, deducting it from storage.
     * 
     * If the specified amount exists in storage, it is processed, and its monetary 
     * value is added to the Government instance.
     * 
     * @param amount The amount of resource to process.
     */
    void process(int amount);

    /**
     * @brief Stores a specified amount of resource, increasing the current storage up to max capacity.
     * 
     * If adding the specified amount does not exceed the max storage capacity, 
     * it is added to the current storage level.
     * 
     * @param amount The amount of resource to store.
     */
    void store(int amount);

    /**
     * @brief Displays the current storage status and calls the resource's status display.
     * 
     * This function outputs the current storage usage and invokes the resource's 
     * displayStatus() function.
     */
    void display() const;

    /**
     * @brief Returns the current amount of resource in storage.
     * 
     * @return int Current storage level of the resource.
     */
    int getCurrentStorage() const;
};

#endif // INCOMERESOURCEPROCESSOR_H
