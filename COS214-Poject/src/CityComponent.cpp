#include "NPCObserver.h"
#include "CityComponent.h"
#include "NPCManager.h"
#include "Government.h"
#include "ReactingNPCS.h"

#include "Government.h"
#include "ReactingNPCS.h"
#include "NPCManager.h"

void CityComponent::addNpc()
{
    // Calculate dynamic population growth based on city building data
    int residentialBuildings = Government::getInstance().getBuildingAmount("Residential");
    int utilityBuildings = Government::getInstance().getBuildingAmount("Utility");
    int publicServiceBuildings = Government::getInstance().getBuildingAmount("Public Service");

    // Base population growth formula, adjusted by city infrastructure
    int populationGrowth = (residentialBuildings * 3) + (utilityBuildings * 2) /* + publicServiceBuildings */;
    Government::getInstance().setPopulationGrowth(populationGrowth);

    // Simulate citizens arriving in increments based on population growth
    ReactingNPCS prototypeNPC;
    for (int i = 0; i < populationGrowth; i++) {
        NPCObserver* newNPC = prototypeNPC.clone();
        observers.push_back(newNPC);
    }

	Government::getInstance().increasePopulation(populationGrowth);

    // Adjust happiness level based on available housing and jobs
    int availableHouses = residentialBuildings * 5;  // Assume each residential building can house 5 citizens
    int availableJobs = (utilityBuildings + publicServiceBuildings) * 3;  // Assume each utility and public service provides 3 jobs

    // Modify happiness based on whether there are enough houses and jobs
    if (populationGrowth <= availableHouses && populationGrowth <= availableJobs) {
        NPCManager::getInstance().setHappinessLevel(5);  // Increase happiness due to good living conditions
    } else if (populationGrowth > availableHouses) {
        NPCManager::getInstance().setHappinessLevel(-3);  // Decrease happiness due to lack of housing
    } else if (populationGrowth > availableJobs) {
        NPCManager::getInstance().setHappinessLevel(-2);  // Decrease happiness due to lack of jobs
    }
    
    std::cout << populationGrowth << " citizens have arrived in the city.\n";
    notify();
}


void CityComponent::removeNpc()
{
    int population = Government::getInstance().getPopulation();
    int decrease = 0;
    double deathPercentage = 0;

    if (NPCManager::getInstance().getHighestState() == "Crime")
    {
        deathPercentage = 0.01;
    }
    else if (NPCManager::getInstance().getHighestState() == "Revolt")
    {
        deathPercentage = 0.25;
    }
    decrease = static_cast<int>(population * deathPercentage);

    while (decrease && !observers.empty())
    {
        delete observers.front();
        observers.erase(observers.begin());
        Government::getInstance().decreasePopulation(1);  // Decrease by one per removal
        --decrease;
    }
    
    if (observers.empty() && decrease > 0)
    {
        std::cout << "No citizens to remove\n";
    }
}


void CityComponent::notify()
{
	for (auto observer : observers)
	{
		observer->update();
	}
}

CityComponent::~CityComponent()
{
    for (auto observer : observers)
    {
        delete observer;
    }
}

void CityComponent::setLocation(int x,int y){
	location = Location(x, y);
}

void CityComponent::setLocation(const Location &loc){
	location = loc;
}


Location CityComponent::getLocation() const{
	return location;
}

