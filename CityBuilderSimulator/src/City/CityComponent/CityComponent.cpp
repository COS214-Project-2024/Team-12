#include "../NPCs/UselessNPC/NPCObserver.h"
#include "CityComponent.h"
#include "../NPCs/NPCManager.h"
#include "../Government.h"
#include "../NPCs/UselessNPC/ReactingNPCS.h"

void CityComponent::addNpc()
{
	//	Government::getInstance().;//Increases population
	// observers.push_back(npcs);
	int populationGrowth = Government::getInstance().getPopulationGrowth();
	for (int i = 0; i < populationGrowth; i++)
	{
		ReactingNPCS *npcPrototype = new ReactingNPCS(); // Create a prototype NPC
		NPCObserver *newNPC = npcPrototype->clone();	 // Clone the prototype
		observers.push_back(newNPC);					 // Add to NPC collection
		delete npcPrototype;							 // Clean up the prototype after cloning
	}
}

void CityComponent::removeNpc()
{
	// observers.erase(std::remove(observers.begin(), observers.end(), npcs), observers.end());
	int population = Government::getInstance().getPopulation();
	int decrease = 0;
	double deathPercentage = 0;
	if (NPCManager::getInstance().getHighestState() == "Crime")
	{
		deathPercentage = 0.01;
		decrease = population * deathPercentage;
	}
	else if (NPCManager::getInstance().getHighestState() == "Revolt")
	{
		deathPercentage = 0.25;
		decrease = population * deathPercentage;
	}

	while (decrease)
	{
		if (!observers.empty())
		{
			delete observers.front();
			observers.erase(observers.begin());
			Government::getInstance().decreasePopulation(decrease);
		}
		else
		{
			std::cout << "No citizens to remove\n";
		}
	}
}

void CityComponent::notify()
{
	for (auto observer : observers)
	{
		observer->update();
	}
}