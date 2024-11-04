#include "CityComposite.h"
#include "CityComponent.h"
#include "NPCObserver.h"
#include "Government.h"
#include "NPCManager.h"

#include <iostream>
#include <vector>
#include <string>

CityComposite::CityComposite(const std::string &name) : cityName(name) {}

CityComposite::~CityComposite()
{
    for (auto zone : zones)
    {
        //delete zone;
    }
    zones.clear();
}

void CityComposite::add(std::shared_ptr<CityComponent> component)
{
    zones.push_back(component);
    if(Government::getInstance().getPopulation() != 0){
        updateHappinessForNewComponent(component);
    }
}

void CityComposite::remove(std::shared_ptr<CityComponent> component)
{
    zones.erase(std::remove(zones.begin(), zones.end(), component), zones.end());
}

void CityComposite::displayStatus()
{
    std::cout << "City: " << cityName << "\n";
    for (auto &zone : zones)
    {
        zone->displayStatus();
    }

    Government::getInstance().displayGovernmentStats();
}

/* double CityComposite::getBudget() const
{
    return Government::getInstance().getMoney();
}

// Deduct budget for buying, upgrading and repairing
bool CityComposite::deductBudget(double amount)
{
    if (Government::getInstance().getMoney() >= amount)
    {
        Government::getInstance().reduceMoney(amount);
        return true;
    }
    else
    {
        std::cout << "Insufficient budget.\n";
        return false;
    }
}
void CityComposite::addBudget(double amount)
{
    if (amount > 0)
    {
        Government::getInstance().addMoney(amount);
    }
    else
    {
        std::cout << "Invalid amount. Budget not updated.\n";
    }
} */

bool CityComposite::checkCityConditions()
{
    int publicServiceBuildings = Government::getInstance().getBuildingAmount("Public Service");
    int residentialBuildings = Government::getInstance().getBuildingAmount("Residential");
    int utilityBuildings = Government::getInstance().getBuildingAmount("Utility");

    if ((publicServiceBuildings >= 5 && publicServiceBuildings <= 7) &&
        (residentialBuildings >= 3 && residentialBuildings <= 10) &&
        (utilityBuildings >= 2 && utilityBuildings <= 5))
    {
        Government::getInstance().setPopulationGrowth(5);
        return true;
    }
    else if ((publicServiceBuildings >= 8 && publicServiceBuildings <= 12) &&
             (residentialBuildings >= 6 && residentialBuildings <= 15) &&
             (utilityBuildings >= 8 && utilityBuildings <= 12))
    {
        Government::getInstance().setPopulationGrowth(10);
        return true;
    }
    return false;
}

// void CityComposite::connectZones(CityComponent *zoneA, CityComponent *zoneB, std::unique_ptr<Transport> transport)
// {
//     // Find map locations of zones and connect them
//     Node *startNode = map->getNode(zoneA->getLocation().x, zoneA->getLocation().y);
//     Node *endNode = map->getNode(zoneB->getLocation().x, zoneB->getLocation().y);

//     if (startNode && endNode)
//     {
//         map->connectNodes(startNode->location, endNode->location, std::move(transport));
//     }
//     else
//     {
//         std::cout << "Failed to connect zones.\n";
//     }
// }

/* void CityComposite::connectZones(CityComponent* zoneA, CityComponent* zoneB, 
                                std::unique_ptr<Transport> transport) {
    Location startLoc = zoneA->getLocation();
    Location endLoc = zoneB->getLocation();

    if (map->connectLocations(startLoc, endLoc, std::move(transport))) {
        std::cout << "Zones connected successfully!\n";
    } else {
        std::cout << "Failed to connect zones.\n";
    }
}
 */

void CityComposite::updateHappinessForNewComponent(const std::shared_ptr<CityComponent>& component) {
    // Base happiness modifier for new components
    int happinessImpact = 0;

    // Determine happiness impact based on component type
    if (component->getBuildingType() == "House") {
        happinessImpact = 1;  // Base happiness for residential buildings
    } 
    else if (component->getBuildingType() == "Flat" || component->getBuildingType() == "Townhouse" || component->getBuildingType() == "Estate") {
        happinessImpact = 2;  // More happiness for higher-end residential buildings
    } 
    else if (component->getBuildingType() == "Shop" || component->getBuildingType() == "Mall") {
        happinessImpact = 3;  // Happiness boost for commercial buildings
        Government::getInstance().increaseEmploymentRate(5);  // Increase employment due to new jobs
    } 
    else if (component->getBuildingType() == "Office") {
        happinessImpact = 2;  // Moderate happiness boost for offices
        Government::getInstance().increaseEmploymentRate(8);  // Larger employment boost
    } 
    else if (component->getBuildingType() == "MetalWorkFacility" || component->getBuildingType() == "PetrochemicalFacility" ||
             component->getBuildingType() == "CrystalCraftIndustry" || component->getBuildingType() == "WoodAndCoalPlant") {
        happinessImpact = -2;  // Industrial pollution decreases happiness
        Government::getInstance().increaseEmploymentRate(10);  // Significant employment increase
        Government::getInstance().incrementPollutionLevel(5);  // Increase pollution
    } 
    else if (component->getBuildingType() == "Utility") {
        happinessImpact = 2;  // Utilities boost happiness in surrounding areas
    } 
    else if (component->getBuildingType() == "Park" || component->getBuildingType() == "Monument" || component->getBuildingType() == "CulturalCenter") {
        happinessImpact = 4;  // Landmarks provide a strong happiness boost
    }

    // Adjust happiness in NPCManager
    NPCManager::getInstance().setHappinessLevel(happinessImpact);

    // Notify observers if needed (e.g., for GUI updates)
    notify();
}

void CityComposite::adjustHappinessBasedOnTaxRate() {
    auto& government = Government::getInstance();
    auto& npcManager = NPCManager::getInstance();

    double taxRate = government.getIncomeTaxRate(); // Income tax rate (0.0 to 1.0)
    int happinessAdjustment = 0; // Default to no change

    // Define tax rate thresholds
    if (taxRate <= 0.1) { 
        happinessAdjustment = 2;  // Slight increase for low tax rates
    } 
    else if (taxRate > 0.1 && taxRate <= 0.2) { 
        happinessAdjustment = -1; // Small decrease
    }
    else if (taxRate > 0.2 && taxRate <= 0.3) {
        happinessAdjustment = -3; // Noticeable decrease
    } 
    else if (taxRate > 0.3) {
        happinessAdjustment = -5; // Significant decrease
    }

    // Apply the happiness adjustment
    npcManager.setHappinessLevel(happinessAdjustment);

    // Provide feedback
    std::cout << "Tax rate is at " << (taxRate * 100) << "%, adjusting happiness by " 
              << happinessAdjustment << " points.\n";
}
