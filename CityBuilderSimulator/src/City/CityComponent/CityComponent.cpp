#include "../NPCs/UselessNPC/NPCObserver.h"
#include "CityComponent.h"
#include "../NPCs/NPCManager.h"

void CityComponent::addNpc(NPCObserver* npcs){
	NPCManager::getInstance().setPopulationGrowth(1);//Increases population
	observers.push_back(npcs);
}

void CityComponent::removeNpc(NPCObserver* npcs){
	observers.erase(std::remove(observers.begin(), observers.end(), npcs), observers.end());
}

void CityComponent::notify(){
	for (auto observer : observers) {
		observer->update();
}