#include "IncomeResourceProcessor.h"

/**
 * @brief Constructs an IncomeResourceProcessor with a given resource and storage limit.
 * 
 * @param res Shared pointer to an IncomeResourceProduct to be processed.
 * @param maxStorage Maximum storage capacity for the resource.
 */
IncomeResourceProcessor::IncomeResourceProcessor(std::shared_ptr<IncomeResourceProduct> res, int maxStorage) 
        : resource(res), currentStorage(0), maxStorage(maxStorage) {}

/**
 * @brief Processes a specified amount of resource, deducting it from storage and adding its monetary value to the government.
 * 
 * If the current storage has at least the specified amount, it is processed by deducting 
 * the amount from the storage and calculating the monetary value based on the resource's 
 * market value. The processed amount and monetary value are added to the Government instance.
 * 
 * @param amount The amount of resource to process.
 */
void IncomeResourceProcessor::process(int amount) {
    if (currentStorage >= amount && resource) {
        currentStorage -= amount;
        double value = amount * resource->getMarketValue();

        Government::getInstance().addProcessedResource(
            resource->getName(),
            amount, 
            resource->getMarketValue()
        );
        Government::getInstance().addMoney(value);

        std::cout << "Processed " << amount << " units of " << resource->getName() << ". Earned $" << value << ".\n";
    } else {
        std::cout << "Not enough resources in storage to process.\n";
    }
}

/**
 * @brief Stores a specified amount of resource, increasing the current storage up to the maximum limit.
 * 
 * If adding the specified amount does not exceed the max storage capacity, it is added to the 
 * current storage. Otherwise, a warning is issued that the storage capacity has been exceeded.
 * 
 * @param amount The amount of resource to store.
 */
void IncomeResourceProcessor::store(int amount) {
    if (currentStorage + amount <= maxStorage) {
        currentStorage += amount;
        std::cout << "Stored " << amount << " units of " << resource->getName() << ". Current Storage: " << currentStorage << "/" << maxStorage << std::endl;
    } else {
        std::cout << "Storage capacity exceeded! Current Storage: " << currentStorage << "/" << maxStorage << std::endl;
    }
}

/**
 * @brief Displays the current storage status and resource status information.
 * 
 * This function outputs the current storage usage and calls the resource's displayStatus() function.
 */
void IncomeResourceProcessor::display() const {
    std::cout << "Income Resource Storage: " << currentStorage
            << "/" << maxStorage << "\n";
    resource->displayStatus();
}

/**
 * @brief Returns the current amount of resource in storage.
 * 
 * @return int Current storage level of the resource.
 */
int IncomeResourceProcessor::getCurrentStorage() const { return currentStorage; }
