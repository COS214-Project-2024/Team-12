#ifndef CONSTRUCTIONRESOURCEPROCESSOR_H
#define CONSTRUCTIONRESOURCEPROCESSOR_H

#include "ResourceProcessor.h"
#include "ConstructionResourceProduct.h"
#include "Government.h"
#include <memory>

/**
 * @class ConstructionResourceProcessor
 * @brief Manages the processing and storage of construction resources within the game.
 * 
 * This class handles construction resources by allowing processing and storage 
 * up to a defined maximum capacity, and it provides methods to display the resource status.
 */
class ConstructionResourceProcessor : public ResourceProcessor {
private:
    std::shared_ptr<ConstructionResourceProduct> resource;  /**< The construction resource being processed. */
    int currentStorage;  /**< The current amount of resource in storage. */
    const int maxStorage; /**< The maximum storage capacity for the resource. */

public:
    /**
     * @brief Constructs a ConstructionResourceProcessor with specified resource and storage capacity.
     * 
     * @param res A shared pointer to the construction resource product to be processed.
     * @param maxStorage The maximum storage capacity for this processor.
     */
    ConstructionResourceProcessor(std::shared_ptr<ConstructionResourceProduct> res, int maxStorage);

    /**
     * @brief Processes a specified amount of the resource.
     * 
     * Handles resource processing logic, consuming a certain amount of the stored resource.
     * 
     * @param amount The amount of resource to process.
     */
    void process(int amount);

    /**
     * @brief Stores a specified amount of the resource, if capacity allows.
     * 
     * Adds the given amount of resource to storage, up to the maximum storage limit.
     * 
     * @param amount The amount of resource to store.
     */
    void store(int amount);

    /**
     * @brief Displays the current status of the resource processor.
     * 
     * Outputs details about the current storage, maximum storage, and the type of resource being managed.
     */
    void display() const;

    /**
     * @brief Gets the current storage amount.
     * 
     * @return The current amount of resource stored.
     */
    int getCurrentStorage() const;
};

#endif
