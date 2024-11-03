#include "IncomeResourceProcessor.h"

IncomeResourceProcessor::IncomeResourceProcessor(std::shared_ptr<IncomeResourceProduct> res, int maxStorage) 
        : resource(res), currentStorage(0), maxStorage(maxStorage) {}

void IncomeResourceProcessor::process(int amount) {
    if (currentStorage >= amount && resource) {
        resource->consumeResources(amount);
        currentStorage -= amount;
        
        double value = amount * resource->getMarketValue();
        // Store both amount and value
        Government::getInstance().addProcessedResource(
            resource->getName(),
            amount, 
            resource->getMarketValue()
        );
        Government::getInstance().addMoney(value);
    }
}

void IncomeResourceProcessor::store(int amount) {
    if (currentStorage + amount <= maxStorage) {
        currentStorage += amount;
        std::cout << "Stored " << amount << " units of income resource.\n";
    } else {
        std::cout << "Storage capacity exceeded!\n";
    }
}

void IncomeResourceProcessor::display() const {
    std::cout << "Income Resource Storage: " << currentStorage
            << "/" << maxStorage << "\n";
    resource->displayStatus();
}

int IncomeResourceProcessor::getCurrentStorage() const{ return currentStorage; }