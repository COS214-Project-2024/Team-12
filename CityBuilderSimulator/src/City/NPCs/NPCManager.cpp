#include "NPCManager.h"

#include <utility>


int NPCManager::getHappinessLevel() const{
	return happinessLevel;
}

void NPCManager::setHappinessLevel(int level){
	if(happinessLevel == 100 || happinessLevel == 0){
		//do nothing as we do not want to increase it so far it becomes difficult to lower it
	}
	else{
		happinessLevel += level;
	}
}

double NPCManager::getMortalityRate() const{
	return mortalityRate;
}

void NPCManager::setMortalityRate(double rate){
	mortalityRate = std::max(0.0, rate);
}

int NPCManager::getPopulationGrowth() const{
	return populationGrowth;
}

void NPCManager::setPopulationGrowth(int growth){
	populationGrowth = growth;
}

int NPCManager::getPopulation() const{
	return population;
}

void NPCManager::updatePopulation(){
	population += populationGrowth - mortalityRate * population;
}