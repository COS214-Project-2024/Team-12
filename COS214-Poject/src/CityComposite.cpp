/**
 * @file CityComposite.cpp
 * @brief Implementation of the CityComposite class, which manages zones, happiness, and tax adjustments for the city.
 * 
 * This file provides implementations for functions related to adding and removing zones, displaying city status, 
 * managing city conditions, and adjusting happiness based on components and tax rates.
 */

#include "CityComposite.h"
#include "CityComponent.h"
#include "NPCObserver.h"
#include "Government.h"
#include "NPCManager.h"

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Constructs a CityComposite object with a given name.
 * 
 * @param name The name of the city.
 */
CityComposite::CityComposite(const std::string &name) : cityName(name) {}

/**
 * @brief Destructor for CityComposite.
 * 
 * Clears all zones managed by the composite.
 */
CityComposite::~CityComposite() {
    for (auto zone : zones) {
        // delete zone; (commented out to prevent double deletion if managed elsewhere)
    }
    zones.clear();
}

/**
 * @brief Adds a city component (zone) to the city.
 * 
 * This function also updates the happiness for the new component if the city already has a population.
 * 
 * @param component A shared pointer to the CityComponent to be added.
 */
void CityComposite::add(std::shared_ptr<CityComponent> component) {
    zones.push_back(component);
    if (Government::getInstance().getPopulation() != 0) {
        updateHappinessForNewComponent(component);
    }
}

/**
 * @brief Removes a city component (zone) from the city.
 * 
 * @param component A shared pointer to the CityComponent to be removed.
 */
void CityComposite::remove(std::shared_ptr<CityComponent> component) {
    zones.erase(std::remove(zones.begin(), zones.end(), component), zones.end());
}

/**
 * @brief Displays the status of the city and its zones.
 * 
 * This function prints the city name, iterates through each zone to display their status,
 * and displays government statistics.
 */
void CityComposite::displayStatus() {
    std::cout << "City: " << cityName << "\n";
    for (auto &zone : zones) {
        zone->displayStatus();
    }
    Government::getInstance().displayGovernmentStats();
}

/**
 * @brief Checks if the city meets specific conditions based on building counts.
 * 
 * This function evaluates conditions based on the number of public service, residential, 
 * and utility buildings, and sets population growth if conditions are met.
 * 
 * @return true if the city conditions are met; false otherwise.
 */
bool CityComposite::checkCityConditions() {
    int publicServiceBuildings = Government::getInstance().getBuildingAmount("Public Service");
    int residentialBuildings = Government::getInstance().getBuildingAmount("Residential");
    int utilityBuildings = Government::getInstance().getBuildingAmount("Utility");

    if ((publicServiceBuildings >= 5 && publicServiceBuildings <= 7) &&
        (residentialBuildings >= 3 && residentialBuildings <= 10) &&
        (utilityBuildings >= 2 && utilityBuildings <= 5)) {
        Government::getInstance().setPopulationGrowth(5);
        return true;
    }
    else if ((publicServiceBuildings >= 8 && publicServiceBuildings <= 12) &&
             (residentialBuildings >= 6 && residentialBuildings <= 15) &&
             (utilityBuildings >= 8 && utilityBuildings <= 12)) {
        Government::getInstance().setPopulationGrowth(10);
        return true;
    }
    return false;
}

/**
 * @brief Updates the city’s happiness level based on the addition of a new component.
 * 
 * This function calculates the impact of a new component on happiness based on its type.
 * It may also adjust employment rates and pollution levels for specific building types.
 * 
 * @param component A shared pointer to the CityComponent being added.
 */
void CityComposite::updateHappinessForNewComponent(const std::shared_ptr<CityComponent>& component) {
    int happinessImpact = 0;

    if (component->getBuildingType() == "House") {
        happinessImpact = 1;
    } 
    else if (component->getBuildingType() == "Flat" || component->getBuildingType() == "Townhouse" || component->getBuildingType() == "Estate") {
        happinessImpact = 2;
    } 
    else if (component->getBuildingType() == "Shop" || component->getBuildingType() == "Mall") {
        happinessImpact = 3;
        Government::getInstance().increaseEmploymentRate(5);
    } 
    else if (component->getBuildingType() == "Office") {
        happinessImpact = 2;
        Government::getInstance().increaseEmploymentRate(8);
    } 
    else if (component->getBuildingType() == "MetalWorkFacility" || component->getBuildingType() == "PetrochemicalFacility" ||
             component->getBuildingType() == "CrystalCraftIndustry" || component->getBuildingType() == "WoodAndCoalPlant") {
        happinessImpact = -2;
        Government::getInstance().increaseEmploymentRate(10);
        Government::getInstance().incrementPollutionLevel(5);
    } 
    else if (component->getBuildingType() == "Utility") {
        happinessImpact = 2;
    } 
    else if (component->getBuildingType() == "Park" || component->getBuildingType() == "Monument" || component->getBuildingType() == "CulturalCenter") {
        happinessImpact = 4;
    }

    NPCManager::getInstance().setHappinessLevel(happinessImpact);
    notify();
}

/**
 * @brief Adjusts the city's happiness level based on the current tax rate.
 * 
 * This function applies a happiness adjustment to NPCs in response to the income tax rate.
 */
void CityComposite::adjustHappinessBasedOnTaxRate() {
    auto& government = Government::getInstance();
    auto& npcManager = NPCManager::getInstance();

    double taxRate = government.getIncomeTaxRate();
    int happinessAdjustment = 0;

    if (taxRate <= 0.1) { 
        happinessAdjustment = 2;
    } 
    else if (taxRate > 0.1 && taxRate <= 0.2) { 
        happinessAdjustment = -1;
    }
    else if (taxRate > 0.2 && taxRate <= 0.3) {
        happinessAdjustment = -3;
    } 
    else if (taxRate > 0.3) {
        happinessAdjustment = -5;
    }

    npcManager.setHappinessLevel(happinessAdjustment);
    std::cout << "Tax rate is at " << (taxRate * 100) << "%, adjusting happiness by " 
              << happinessAdjustment << " points.\n";
}
