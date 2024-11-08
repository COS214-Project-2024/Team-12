/**
 * @file CityComponent.cpp
 * @brief Implementation of the CityComponent class, which handles city component behaviors such as managing NPCs, location, and notifications.
 * 
 * This file provides the implementation for the CityComponent class, including functions
 * for adding and removing NPCs, notifying observers, and setting locations.
 */

#include "NPCObserver.h"
#include "CityComponent.h"
#include "NPCManager.h"
#include "Government.h"
#include "ReactingNPCS.h"

/**
 * @brief Adds NPCs to the city component and adjusts the city's population growth and happiness level.
 * 
 * This method calculates the population growth based on the city's residential and utility infrastructure,
 * creates new NPCs based on this growth, and adjusts the overall happiness level depending on available housing
 * and job opportunities.
 */
void CityComponent::addNpc() {
    // Calculate dynamic population growth based on city building data
    int residentialBuildings = Government::getInstance().getBuildingAmount("Residential");
    int utilityBuildings = Government::getInstance().getBuildingAmount("Utility");
    int publicServiceBuildings = Government::getInstance().getBuildingAmount("Public Service");

    // Base population growth formula, adjusted by city infrastructure
    int populationGrowth = (residentialBuildings * 3) + (utilityBuildings * 2);
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

/**
 * @brief Removes NPCs from the city component based on certain conditions.
 * 
 * This method decreases the population based on the city's highest state (Crime or Revolt), simulating citizen departures
 * or deaths. It removes NPC observers up to the calculated decrease amount.
 */
void CityComponent::removeNpc() {
    int population = Government::getInstance().getPopulation();
    int decrease = 0;
    double deathPercentage = 0;

    if (NPCManager::getInstance().getHighestState() == "Crime") {
        deathPercentage = 0.01;
    } else if (NPCManager::getInstance().getHighestState() == "Revolt") {
        deathPercentage = 0.25;
    }
    decrease = static_cast<int>(population * deathPercentage);

    while (decrease && !observers.empty()) {
        delete observers.front();
        observers.erase(observers.begin());
        Government::getInstance().decreasePopulation(1);  // Decrease by one per removal
        --decrease;
    }
    
    if (observers.empty() && decrease > 0) {
        std::cout << "No citizens to remove\n";
    }
}

/**
 * @brief Notifies all NPC observers of changes in the city component.
 * 
 * This function iterates through the list of observers and calls their `update` method to respond to changes.
 */
void CityComponent::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}

/**
 * @brief Destructor for the CityComponent class.
 * 
 * Cleans up all dynamically allocated NPC observers to prevent memory leaks.
 */
CityComponent::~CityComponent() {
    for (auto observer : observers) {
        delete observer;
    }
}

/**
 * @brief Sets the location of the city component using x and y coordinates.
 * 
 * @param x The x-coordinate of the location.
 * @param y The y-coordinate of the location.
 */
void CityComponent::setLocation(int x, int y) {
    location = Location(x, y);
}

/**
 * @brief Sets the location of the city component using a Location object.
 * 
 * @param loc A Location object representing the new location.
 */
void CityComponent::setLocation(const Location &loc) {
    location = loc;
}

/**
 * @brief Gets the current location of the city component.
 * 
 * @return The current location as a Location object.
 */
Location CityComponent::getLocation() const {
    return location;
}
