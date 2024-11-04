#include "Government.h"

#include <string>
#include <iostream>

void Government::addMoney(double amount){
	money += amount;
}

void Government::reduceMoney(double amount){
	money -= amount;
}

void Government::reduceProduction(double factor){
	productionRate *= (1 - factor);
}

void Government::increaseProduction(double factor){
	productionRate *= (1 + factor);
}

void Government::increaseCrimeRate(double factor){
	crimeRate *= (1 + factor);
	mortalityRate = crimeRate * 0.9;//change it a bot so that the mortality rate is always a bit lower than the crime rate
}

double Government::getMoney() const{
	return money;
}

double Government::getMortalityRate() const{
	return mortalityRate;
}

double Government::getProductionRate() const{
	return productionRate;
}

double Government::getCrimeRate() const{
	return crimeRate;
}

void Government::setCrimeRate(int rate){
	crimeRate = rate/100;
}

int Government::getPopulationGrowth() const{
	return populationGrowth;
}

void Government::setPopulationGrowth(int growth){
	populationGrowth = growth;
}

int Government::getPopulation() const{
	return population;
}

void Government::updatePopulation(){
	population += populationGrowth - mortalityRate * population;
}

void Government::calculateTax(){
	int employedPopulation = static_cast<int>(population * EMPLOYMENT_RATE);
	incomeTax = employedPopulation * incomeTaxRate;
	money += incomeTax;  // Add collected tax to government money
}

void Government::setTax(double rate){
	incomeTaxRate = rate;
}

void Government::increaseEmploymentRate(double rate){
	EMPLOYMENT_RATE = rate;
}

void Government::setProductionRate(double rate){
	productionRate = rate;
}

void Government::setBuildingAmount(std::string type, int amount){
	if(type == "Residential"){
		residentialAmount += amount;
	}else if(type == "Utility"){
		utilityAmount += amount;
	}else if(type == "Public Service"){
		publicServiceAmount += amount;
	}
}

int Government::getBuildingAmount(std::string type){
	if(type == "Residential"){
		return residentialAmount;
	}else if("Utility"){
		return utilityAmount;
	}else if("Public Service"){
		return publicServiceAmount;
	}
}

void Government::displayGovernmentStats(){
	std::cout << "Government Stats:" << std::endl;
	std::cout << "Population: " << population << std::endl;
	std::cout << "Money: " << money << std::endl;
	std::cout << "Income Tax rate: " << incomeTaxRate << std::endl;
	std::cout << "Employment Rate: " << EMPLOYMENT_RATE << "%\n";
	std::cout << "Production Rate: " << productionRate << std::endl;
	std::cout << "Crime Rate: " << crimeRate <<std::endl;
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

void Government::decreasePopulation(int amount){
	population -= amount;
}

void Government::addProcessedResource(const std::string& resourceName, int amount, double value = 0.0) {
	processedResources[resourceName] += amount;
	resourceValues[resourceName] = value;  // Store the value/unit
}

void Government::increasePopulation(int amount){
	population += amount;
}
void Government::incrementPollutionLevel(int amount){
	pollutionLevel += amount;
}

void Government::decrementPollutionLevel(int amount){
	pollutionLevel -= amount;
}

int Government::getPollutionLevel(){
	return pollutionLevel;
}

double Government::getIncomeTaxRate(){
	return incomeTaxRate;
}