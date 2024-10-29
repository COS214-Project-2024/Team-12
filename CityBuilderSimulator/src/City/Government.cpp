#include "Government.h"

void Government::addMoney(double amount){
	money += amount;
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
	EMPLOYMENT_RATE = rate/100;
}

void Government::setProductionRate(double rate){
	productionRate = rate;
}