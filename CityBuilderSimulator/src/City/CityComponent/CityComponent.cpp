#include "../NPCs/UselessNPC/NPCObserver.h"
#include "CityComponent.h"
#include "../NPCs/NPCManager.h"
#include "../Government.h"

void CityComponent::addNpc()
{
	//	Government::getInstance().;//Increases population
	//observers.push_back(npcs);
	
}

void CityComponent::removeNpc()
{
	//observers.erase(std::remove(observers.begin(), observers.end(), npcs), observers.end());
}

void CityComponent::notify()
{
	for (auto observer : observers)
	{
		observer->update();
	}
} 