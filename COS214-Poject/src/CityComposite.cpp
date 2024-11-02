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
        /* if(component->getBuildingType() == "Resdiential")
        {
            NPCManager::getInstance().setHappinessLevel(2);
            Government::getInstance().reduceMoney(500);
        } */
    }
    

    notify(); 
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
} */

// Deduct budget for buying, upgrading and repairing
/* bool CityComposite::deductBudget(double amount)
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
} */
/* void CityComposite::addBudget(double amount)
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

/* void CityComposite::connectZones(CityComponent *zoneA, CityComponent *zoneB, std::unique_ptr<Transport> transport)
{
    // Find map locations of zones and connect them
    Node *startNode = map->getNode(zoneA->getLocation().x, zoneA->getLocation().y);
    Node *endNode = map->getNode(zoneB->getLocation().x, zoneB->getLocation().y);

    if (startNode && endNode)
    {
        map->connectNodes(startNode->location, endNode->location, std::move(transport));
    }
    else
    {
        std::cout << "Failed to connect zones.\n";
    }
} */
