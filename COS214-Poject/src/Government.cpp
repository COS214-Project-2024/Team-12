#include "Government.h"

#include <string>
#include <iostream>

/**
 * @brief Adds a specified amount of money to the government funds.
 * 
 * @param amount The amount of money to add.
 */
void Government::addMoney(double amount) {
    money += amount;
}

/**
 * @brief Reduces the government funds by a specified amount.
 * 
 * @param amount The amount of money to reduce.
 */
void Government::reduceMoney(double amount) {
    money -= amount;
}

/**
 * @brief Reduces the production rate by a specified factor.
 * 
 * @param factor The factor by which to reduce production.
 */
void Government::reduceProduction(double factor) {
    productionRate *= (1 - factor);
}

/**
 * @brief Increases the production rate by a specified factor.
 * 
 * @param factor The factor by which to increase production.
 */
void Government::increaseProduction(double factor) {
    productionRate *= (1 + factor);
}

/**
 * @brief Increases the crime rate by a specified factor.
 * 
 * @param factor The factor by which to increase crime.
 */
void Government::increaseCrimeRate(double factor) {
    crimeRate *= (1 + factor);
    mortalityRate = crimeRate * 0.9; // Adjust mortality rate based on crime rate
}

/**
 * @brief Gets the current amount of money the government has.
 * 
 * @return double The current money.
 */
double Government::getMoney() const {
    return money;
}

/**
 * @brief Gets the current mortality rate.
 * 
 * @return double The current mortality rate.
 */
double Government::getMortalityRate() const {
    return mortalityRate;
}

/**
 * @brief Gets the current production rate of the government.
 * 
 * @return double The current production rate.
 */
double Government::getProductionRate() const {
    return productionRate;
}

/**
 * @brief Gets the current crime rate.
 * 
 * @return double The current crime rate.
 */
double Government::getCrimeRate() const {
    return crimeRate;
}

/**
 * @brief Sets the crime rate.
 * 
 * @param rate The new crime rate as a percentage.
 */
void Government::setCrimeRate(int rate) {
    crimeRate = rate / 100.0; // Convert percentage to a decimal
}

/**
 * @brief Gets the current population growth rate.
 * 
 * @return int The current population growth rate.
 */
int Government::getPopulationGrowth() const {
    return populationGrowth;
}

/**
 * @brief Sets the population growth rate.
 * 
 * @param growth The new population growth rate.
 */
void Government::setPopulationGrowth(int growth) {
    populationGrowth = growth;
}

/**
 * @brief Gets the current population of the city.
 * 
 * @return int The current population.
 */
int Government::getPopulation() const {
    return population;
}

/**
 * @brief Updates the population based on growth and mortality rate.
 */
void Government::updatePopulation() {
    population += populationGrowth - static_cast<int>(mortalityRate * population);
}

/**
 * @brief Calculates the income tax based on the current population and tax rate.
 */
void Government::calculateTax() {
    int employedPopulation = static_cast<int>(population * EMPLOYMENT_RATE);
    incomeTax = employedPopulation * incomeTaxRate;
    money += incomeTax;  // Add collected tax to government money
}

/**
 * @brief Sets the income tax rate.
 * 
 * @param rate The new income tax rate.
 */
void Government::setTax(double rate) {
    incomeTaxRate = rate;
}

/**
 * @brief Increases the employment rate by a specified amount.
 * 
 * @param rate The amount to increase the employment rate.
 */
void Government::increaseEmploymentRate(double rate) {
    EMPLOYMENT_RATE = rate;
}

/**
 * @brief Sets the production rate of the government.
 * 
 * @param rate The new production rate.
 */
void Government::setProductionRate(double rate) {
    productionRate = rate;
}

/**
 * @brief Sets the amount of a specified building type.
 * 
 * @param type The type of building.
 * @param amount The amount of the building type to set.
 */
void Government::setBuildingAmount(std::string type, int amount) {
    if (type == "Residential") {
        residentialAmount += amount;
    } else if (type == "Utility") {
        utilityAmount += amount;
    } else if (type == "Public Service") {
        publicServiceAmount += amount;
    }
}

/**
 * @brief Gets the amount of a specified building type.
 * 
 * @param type The type of building.
 * @return int The amount of the specified building type.
 */
int Government::getBuildingAmount(std::string type) {
    if (type == "Residential") {
        return residentialAmount;
    } else if (type == "Utility") {
        return utilityAmount;
    } else if (type == "Public Service") {
        return publicServiceAmount;
    }
    return 0; // Default return if type does not match
}

/**
 * @brief Displays the current statistics of the government.
 */


void Government::displayGovernmentStats(){
	std::cout << "Government Stats:" << std::endl;
	std::cout << "Population: " << population << std::endl;
	std::cout << "Money: " << money << std::endl;
	std::cout << "Income Tax rate: " << incomeTaxRate << std::endl;
	std::cout << "Employment Rate: " << EMPLOYMENT_RATE << "%\n";
	std::cout << "Production Rate: " << productionRate << std::endl;
	//std::cout << "Crime Rate: " << crimeRate <<std::endl;
	std::cout << "Mortality Rate: " << mortalityRate <<std::endl;
	std::cout << "Population growth: " << mortalityRate <<std::endl;




    // Display Resource Information
    std::cout << "\n=== Resource Treasury ===" << std::endl;
    
    // Income Resources
    std::cout << "Income Resources:" << std::endl;
    if (processedResources.count("Gold")) 
        std::cout << "  Gold: " << processedResources["Gold"] << " units (Value: $"
                    << processedResources["Gold"] * resourceValues["Gold"] << ")" << std::endl;
    if (processedResources.count("Diamond")) 
        std::cout << "  Diamond: " << processedResources["Diamond"] << " units (Value: $"
                    << processedResources["Diamond"] * resourceValues["Diamond"] << ")" << std::endl;
    if (processedResources.count("Coal")) 
        std::cout << "  Coal: " << processedResources["Coal"] << " units (Value: $"
                    << processedResources["Coal"] * resourceValues["Coal"] << ")" << std::endl;
    if (processedResources.count("Oil")) 
        std::cout << "  Oil: " << processedResources["Oil"] << " units (Value: $"
                    << processedResources["Oil"] * resourceValues["Oil"] << ")" << std::endl;
    
    // Construction Resources
    std::cout << "\nConstruction Resources:" << std::endl;
    if (processedResources.count("Steel"))
        std::cout << "  Steel: " << processedResources["Steel"] << " units" << std::endl;
    if (processedResources.count("Wood"))
        std::cout << "  Wood: " << processedResources["Wood"] << " units" << std::endl;
    if (processedResources.count("Stone"))
        std::cout << "  Stone: " << processedResources["Stone"] << " units" << std::endl;
    if (processedResources.count("Concrete"))
        std::cout << "  Concrete: " << processedResources["Concrete"] << " units" << std::endl;
    
    // Total Resource Value
    double totalResourceValue = 0;
    for (const auto& [resource, amount] : processedResources) {
        totalResourceValue += amount * resourceValues[resource];
    }
    std::cout << "\nTotal Resource Value: $" << totalResourceValue << std::endl;
    std::cout << "Total Treasury: $" << (money + totalResourceValue) << std::endl;
}

/**
 * @brief Decreases the population by a specified amount.
 * 
 * @param amount The amount to decrease the population.
 */
void Government::decreasePopulation(int amount) {
    population -= amount;
}

/**
 * @brief Adds a processed resource to the government's records.
 * 
 * @param resourceName The name of the resource.
 * @param amount The amount of the resource.
 * @param value The market value of the resource (optional).
 */
void Government::addProcessedResource(const std::string& resourceName, int amount, double value) {
    processedResources[resourceName] += amount;
    resourceValues[resourceName] = value;  // Store the value/unit
}

/**
 * @brief Increases the population by a specified amount.
 * 
 * @param amount The amount to increase the population.
 */
void Government::increasePopulation(int amount) {
    population += amount;
}

/**
 * @brief Increments the pollution level by a specified amount.
 * 
 * @param amount The amount to increment pollution.
 */
void Government::incrementPollutionLevel(int amount) {
    pollutionLevel += amount;
}

/**
 * @brief Decrements the pollution level by a specified amount.
 * 
 * @param amount The amount to decrement pollution.
 */
void Government::decrementPollutionLevel(int amount) {
    pollutionLevel -= amount;
}

/**
 * @brief Gets the current pollution level.
 * 
 * @return int The current pollution level.
 */
int Government::getPollutionLevel() {
    return pollutionLevel;
}

/**
 * @brief Gets the current income tax rate.
 * 
 * @return double The current income tax rate.
 */
double Government::getIncomeTaxRate() {
    return incomeTaxRate;
}
