#include "ConstructionResourceProcessor.h"

ConstructionResourceProcessor::ConstructionResourceProcessor(std::shared_ptr<ConstructionResourceProduct> res, int maxStorage = 200)
        : resource(res), currentStorage(0), maxStorage(maxStorage) {}

void ConstructionResourceProcessor::process(int amount) {
    if (currentStorage >= amount && resource) {
        resource->ConsumeResource(amount);
        currentStorage -= amount;
        
        Government::getInstance().addProcessedResource(
            resource->getName(), 
            amount,
            resource->getUnitCost()
        );
    }
}

void ConstructionResourceProcessor::store(int amount){
    if (currentStorage + amount <= maxStorage) {
        currentStorage += amount;
        std::cout << "Stored " << amount << " units of construction resource.\n";
    } else {
        std::cout << "Storage capacity exceeded!\n";
    }
}

void ConstructionResourceProcessor::display() const  {
    std::cout << "Construction Resource Storage: " << currentStorage 
                << "/" << maxStorage << "\n";
    resource->displayStatus();
}

int ConstructionResourceProcessor::getCurrentStorage() const{ return currentStorage; }