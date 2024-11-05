/**
 * @file ConstructionResourceProcessor.cpp
 * @brief Implementation of the ConstructionResourceProcessor class, managing processing and storage of construction resources.
 */

#include "ConstructionResourceProcessor.h"

/**
 * @brief Constructs a ConstructionResourceProcessor with the given resource and maximum storage capacity.
 * 
 * Initializes the processor with a specific construction resource and sets the maximum storage capacity.
 * 
 * @param res A shared pointer to the construction resource to be processed.
 * @param maxStorage The maximum capacity for storing this resource.
 */
ConstructionResourceProcessor::ConstructionResourceProcessor(std::shared_ptr<ConstructionResourceProduct> res, int maxStorage)
        : resource(res), currentStorage(0), maxStorage(maxStorage) {}

/**
 * @brief Processes a specified amount of the resource.
 * 
 * Decreases the storage by the specified amount if enough resource is available, 
 * and adds the processed resource to the government's resources. 
 * Outputs a message if there isn't enough in storage to process the requested amount.
 * 
 * @param amount The quantity of the resource to process.
 */
void ConstructionResourceProcessor::process(int amount) {
    if (currentStorage >= amount && resource) {
        currentStorage -= amount;

        Government::getInstance().addProcessedResource(
            resource->getName(), 
            amount,
            resource->getUnitCost()
        );

        std::cout << "Processed " << amount << " units of " << resource->getName() << ".\n";
    } else {
        std::cout << "Not enough resources in storage to process.\n";
    }
}

/**
 * @brief Stores a specified amount of the resource.
 * 
 * Increases the storage by the specified amount if it doesn’t exceed the max capacity. 
 * Outputs a message if storage is full.
 * 
 * @param amount The quantity of the resource to store.
 */
void ConstructionResourceProcessor::store(int amount){
    if (currentStorage + amount <= maxStorage) {
        currentStorage += amount;
        std::cout << "Stored " << amount << " units of construction resource.\n";
    } else {
        std::cout << "Storage capacity exceeded!\n";
    }
}

/**
 * @brief Displays the current storage status of the resource processor.
 * 
 * Outputs the current and maximum storage levels, as well as the resource’s details.
 */
void ConstructionResourceProcessor::display() const  {
    std::cout << "Construction Resource Storage: " << currentStorage 
                << "/" << maxStorage << "\n";
    resource->displayStatus();
}

/**
 * @brief Gets the current storage amount of the resource.
 * 
 * @return The amount of resource currently stored.
 */
int ConstructionResourceProcessor::getCurrentStorage() const { 
    return currentStorage; 
}
