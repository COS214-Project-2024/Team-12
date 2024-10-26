#include "../NPCs/UselessNPC/NPCObserver.h"
#include "CityComponent.h"

void CityComponent::addNpc(NPCObserver* npcs){
	observers.push_back(npcs);
}

void CityComponent::removeNpc(NPCObserver* npcs){
	observers.erase(std::remove(observers.begin(), observers.end(), npcs), observers.end());
}

void CityComponent::notify(){
	for (auto observer : observers) {
		observer->update();
}