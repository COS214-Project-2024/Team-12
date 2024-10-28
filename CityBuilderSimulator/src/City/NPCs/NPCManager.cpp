#include "NPCManager.h"

#include <utility>
#include <string>


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

/* void NPCManager::adjustStateCounts(int happyChange, int neutralChange, int revoltChange, int productiveChange, int crimeChange){
	this->happyCount += happyChange;
    this->neutralCount += neutralChange;
    this->revoltCount += revoltChange;
	this->productiveCount += productiveChange;
	this->crimeCount += crimeChange;
} */

void NPCManager::incrementCount(const std::string& stateName){
	    if (stateName == "Donation") happyCount++;
        else if (stateName == "Productive") productiveCount++;
        else if (stateName == "Crime") crimeCount++;
        else if (stateName == "Revolt") revoltCount++;
        else if (stateName == "Neutral") neutralCount++;
}

void NPCManager::decrementCount(const std::string& stateName){
	if (stateName == "Donation") happyCount--;
    else if (stateName == "Productive") productiveCount--;
    else if (stateName == "Crime") crimeCount--;
    else if (stateName == "Revolt") revoltCount--;
    else if (stateName == "Neutral") neutralCount--;
}

int NPCManager::getDonationCount() const{
	return happyCount;
}

int NPCManager::getNeutralCount() const{
	return neutralCount;
}

int NPCManager::getRevoltCount() const{
	return revoltCount;
}

int NPCManager::getProductiveCount() const{
	return productiveCount;
}

int NPCManager::getCrimeCount() const{
	return crimeCount;
}

void NPCManager::resetCounts(){
	happyCount = 0;
	neutralCount = 0;
	revoltCount = 0;
	productiveCount = 0;
	crimeCount = 0;
}