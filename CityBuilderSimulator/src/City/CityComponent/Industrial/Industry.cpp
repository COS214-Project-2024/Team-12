#include "Industry.h"

Industry::Industry() : industryName(""), incomeResource(nullptr), constructionResource(nullptr) {}

Industry::Industry(const std::string& name, 
            std::shared_ptr<IncomeResourceProduct> incomeRes, 
            std::shared_ptr<ConstructionResourceProduct> constructionRes)
        : industryName(name), incomeResource(std::move(incomeRes)), constructionResource(std::move(constructionRes)) {}

bool Industry::gatherResourceManually(int amount, ResourcePriority resourceType) {
    if (checkStorage(amount)) {
        if (resourceType == ResourcePriority::Income) {
            incomeResource->consumeResources(amount);
            std::cout << "Manually gathered " << amount << " units of income resource.\n";
        } else {
            constructionResource->ConsumeResource(amount);
            std::cout << "Manually gathered " << amount << " units of construction resource.\n";
        }
        currentStorage += amount;
        return true;
    } else {
        std::cout << "Not enough storage space to gather more resources.\n";
        return false;
    }
}

void Industry::hireWorkerNPC(const std::string& npcType) {
    workerNPC = NPCContext::hireNPC(npcType);
    if(workerNPC) {
        std::cout << workerNPC->getName() << " hired for $" << workerNPC->getCost() << "\n"; 
    } else {
        std::cout << "Invalid NPC type selected.\n";
    }
}

// Process Income Resource Independently
void Industry::processIncomeResource(int amount) {
    if (currentStorage == 0) {  // Check if storage is empty first
        std::cout << "No resources in storage. Gather resources before processing income resource.\n";
        return;
    }
    if (currentStorage >= amount) {  // Ensure enough resources in storage
        std::cout << industryName << " processing income resource: " 
                  << incomeResource->getQuantity() << " units of " 
                  << incomeResource->getMarketValue() << " per unit." << std::endl;
        incomeResource->consumeResources(amount);
        currentStorage -= amount;  // Decrease storage after processing
    } else {
        std::cout << "Insufficient stored resources to process income resource.\n";
    }
}

// Process Construction Resource Independently
void Industry::processConstructionResource(int amount) {
    if (currentStorage == 0) {  // Check if storage is empty first
        std::cout << "No resources in storage. Gather resources before processing construction resource.\n";
        return;
    }
    if (currentStorage >= amount) {  // Ensure enough resources in storage
        std::cout << industryName << " processing construction resource: " 
                  << constructionResource->getQuantity() << " units at $" 
                  << constructionResource->getUnitCost() << " per unit." << std::endl;
        constructionResource->ConsumeResource(amount);
        currentStorage -= amount;  // Decrease storage after processing
    } else {
        std::cout << "Insufficient stored resources to process construction resource.\n";
    }
}

void Industry::displayResourcesStatus() const {
    std::cout << "Industry: " << industryName << std::endl;
    incomeResource->displayStatus();
    constructionResource->displayStatus();
    std::cout << "Current Storage: " << currentStorage << "/" << maxStorage << std::endl;
    std::cout << "Pollution Level: " << pollutionLevel << "\n" << std::endl;
}

/* double Industry::calculateTaxRevenue() const {
    double incomeTax = incomeResource->getTaxRevenue();
    double constructionTax = constructionResource->getTaxRevenue();
    return incomeTax + constructionTax;
} */

void Industry::setPriorityResource(ResourcePriority priority) {
        priorityResource = priority;
        std::cout << "Priority set to "
                << (priority == ResourcePriority::Income ? "Income Resource" : "Construction Resource") 
                << std::endl;
}

void Industry::processPrioritizedResource(int amount) {
    if (priorityResource == ResourcePriority::Income) {
        processIncomeResource(amount);
    } else {
        processConstructionResource(amount);
    }
}

// Delegate to workerNPC
void Industry::startAutoGathering() {
    autoGatheringActive = true;
}

void Industry::stopAutoGathering() {
    autoGatheringActive = false;
}

void Industry::autoGatherResource(int baseIncomeAmount, int baseConstructionAmount) {
    if (autoGatheringActive && workerNPC) {
        int incomeAmount = workerNPC->collect(baseIncomeAmount);
        int constructionAmount = workerNPC->collect(baseConstructionAmount);

        if (checkStorage(incomeAmount) && checkStorage(constructionAmount)) {
            processIncomeResource(incomeAmount);
            processConstructionResource(constructionAmount);
        } else {
            std::cout << "Not enough storage to gather resources.\n";
        }
    } else if (!workerNPC) {
        std::cout << "No Worker NPC assigned for auto-gathering.\n";
    }
}

bool Industry::checkStorage(int amount) {
    return (currentStorage + amount <= maxStorage);
}

void Industry::increasePollution(int amount) {
    pollutionLevel += amount;
    std::cout << industryName << " pollution level increased to " << pollutionLevel << std::endl;

    if (pollutionLevel > 100) {
        std::cout << "Warning! High pollution level. Consider reducing production or upgrading." << std::endl;
        // Trigger penalties or NPC reaction here
    }
}

void Industry::displayResourcesStatus() const {
    std::cout << "Industry: " << industryName << std::endl;
    incomeResource->displayStatus();
    constructionResource->displayStatus();
    std::cout << "Current Storage: " << currentStorage << "/" << maxStorage << std::endl;
    std::cout << "Pollution Level: " << pollutionLevel << "\n" << std::endl;
}