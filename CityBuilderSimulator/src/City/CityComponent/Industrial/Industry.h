#ifndef INDUSTRY_H
#define INDUSTRY_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include "../src/City/CityComponent/CityComponent.h"
#include "../src/City/CityComponent/Resources/IncomeResourceProduct.h"
#include "../src/City/CityComponent/Resources/ConstructionResourceProduct.h"

// Enum to handle resource prioritization
enum class ResourcePriority { Income, Construction };

class Industry : public CityComponent {
private:
    std::string industryName;
    std::shared_ptr<IncomeResourceProduct> incomeResource;
    std::shared_ptr<ConstructionResourceProduct> constructionResource;
    ResourcePriority priorityResource = ResourcePriority::Income;  // Default priority

    bool autoGatheringActive = false;   // Flag for automated resource gathering
    int maxStorage = 200;               // Max storage capacity for resources
    int currentStorage = 0;             // Track current storage usage
    int pollutionLevel = 0;             // Pollution generated by resource processing

public:
    Industry(); // OR Industry() = default
    Industry(const std::string& name,
            std::shared_ptr<IncomeResourceProduct> incomeRes,
            std::shared_ptr<ConstructionResourceProduct> constructionRes);
    // Process Income Resource Independently
    void processIncomeResource(int amount);

    // Manual Gathering of Resources
    bool gatherResourceManually(int amount, ResourcePriority resourceType);

    // Process Construction Resource Independently
    void processConstructionResource(int amount);

    // Display resource statuses
    void displayResourcesStatus() const;

    // Calculate total tax revenue
    double calculateTaxRevenue() const;


    // Production Prioritization - just a fancy way of showing which resource we are processing
    void setPriorityResource(ResourcePriority priority);

    void processPrioritizedResource(int amount);

    // Automatic Resource Gathering with workerNPCs
    void startAutoGathering();
    void stopAutoGathering();
    void autoGatherResource(int incomeAmount, int constructionAmount);

    // Storage Management
    bool checkStorage(int amount);

    // Environmental Impact Management - To trigger NPC reaction
    void increasePollution(int amount);
};


#endif