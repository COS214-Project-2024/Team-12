#include "NPCManager.h"
#include "Government.h"

#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
 
NPCManager& NPCManager::getInstance(){
    static NPCManager instance;  // Guaranteed to be destroyed, instantiated on first use
        return instance;
}

NPCManager::NPCManager()  : happinessLevel(0), happyCount(0), neutralCount(0), revoltCount(0), productiveCount(0), crimeCount(0), employedNpcs(0) {}

int NPCManager::getHappinessLevel() const{
	return happinessLevel;
}

void NPCManager::setHappinessLevel(int level){
    if(Government::getInstance().getPopulation() == 0){
        return;
    }
	happinessLevel += level;

	if(happinessLevel > 100){
		happinessLevel = 100;
	}
	else if(happinessLevel < 0){
		happinessLevel = 0;
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
	    if (stateName == "DonationState") happyCount++;
        else if (stateName == "ProductiveState") productiveCount++;
        else if (stateName == "CrimeState") crimeCount++;
        else if (stateName == "RevoltState") revoltCount++;
        else if (stateName == "NeutralState") neutralCount++;
}

void NPCManager::decrementCount(const std::string& stateName){
	if (stateName == "DonationState") happyCount--;
    else if (stateName == "ProductiveState") productiveCount--;
    else if (stateName == "CrimeState") crimeCount--;
    else if (stateName == "RevoltState") revoltCount--;
    else if (stateName == "NeutralState") neutralCount--;
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

std::string NPCManager::getHighestState() const{
	// Create pairs of state names and their corresponding counts
        std::pair<std::string, int> states[] = {
            {"Happy", happyCount},
            {"Neutral", neutralCount},
            {"Revolt", revoltCount},
            {"Productive", productiveCount},
            {"Crime", crimeCount}
        };

        // Use a lambda function to find the state with the maximum count
        auto maxState = std::max_element(std::begin(states), std::end(states),
                                         [](const auto& lhs, const auto& rhs) {
                                             return lhs.second < rhs.second;
                                         });

        std::cout << "State with the highest count is: " << maxState->first << " with count: " << maxState->second << std::endl;
        return maxState->first;
}

int NPCManager::getTotalNPCs() const{
    return happyCount + neutralCount + revoltCount + productiveCount + crimeCount;
}

void NPCManager::EmployeedNpcs() { 
    int total = getTotalNPCs();

    if (getHighestState() == "Neutral") {
        employedNpcs = total * 0.85;    // 85% employed
        unemployedNpcs = total * 0.15;  // 15% unemployed
    } else if (getHighestState() == "Happy") {
        employedNpcs = total * 0.92;    // 92% employed
        unemployedNpcs = total * 0.08;  // 8% unemployed
    } else if (getHighestState() == "Productive") {
        employedNpcs = total * 0.88;    // 88% employed
        unemployedNpcs = total * 0.12;  // 12% unemployed
    } else if (getHighestState() == "Crime") {
        employedNpcs = total * 0.75;    // 75% employed
        unemployedNpcs = total * 0.25;  // 25% unemployed, as crime might reduce employment
    } else if (getHighestState() == "Revolt") {
        employedNpcs = total * 0.6;     // 60% employed
        unemployedNpcs = total * 0.4;   // 40% unemployed
    }

    // Update the Government's employment rate based on this information
    double employmentRate = static_cast<double>(employedNpcs) / total * 100;
    Government::getInstance().increaseEmploymentRate(employmentRate);
}

void NPCManager::getCrimeRate(){
    Government::getInstance().setCrimeRate(crimeCount/getTotalNPCs());
}
