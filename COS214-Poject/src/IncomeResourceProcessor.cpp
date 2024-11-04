#include "IncomeResourceProcessor.h"

IncomeResourceProcessor::IncomeResourceProcessor(std::shared_ptr<IncomeResourceProduct> res, int maxStorage) 
        : resource(res), currentStorage(0), maxStorage(maxStorage) {}

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

void IncomeResourceProcessor::store(int amount) {
    if (currentStorage + amount <= maxStorage) {
        currentStorage += amount;
        std::cout << "Stored " << amount << " units of " << resource->getName() << ". Current Storage: " << currentStorage << "/" << maxStorage << std::endl;
    } else {
        std::cout << "Storage capacity exceeded! Current Storage: " << currentStorage << "/" << maxStorage << std::endl;
    }
}

void IncomeResourceProcessor::display() const {
    std::cout << "Income Resource Storage: " << currentStorage
            << "/" << maxStorage << "\n";
    resource->displayStatus();
}

int IncomeResourceProcessor::getCurrentStorage() const{ return currentStorage; }