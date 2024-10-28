#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>


class Government {
public:
    static Government& getInstance() {
        static Government instance;  // Only created once
        return instance;
    }

    // Delete copy constructor and assignment operator to prevent copies
    Government(const Government&) = delete;
    Government& operator=(const Government&) = delete;

    // Government functionality
    void addMoney(double amount);
    void reduceProduction(double factor) { productionRate *= (1 - factor); }
    void increaseProduction(double factor) { productionRate *= (1 + factor); }
    void increaseCrimeRate(double factor) { mortalityRate *= (1 + factor); }

    double getMoney() const { return money; }
    double getProductionRate() const { return productionRate; }
    double getMortalityRate() const { return mortalityRate; }
	double getCrimeRate() const;
	int getPopulationGrowth() const;
	void setPopulationGrowth(int growth);
	int getPopulation() const;
    void updatePopulation();

private:
    Government() : money(10000), productionRate(1.0), mortalityRate(0.01), crimeRate(0.00), population(0), populationGrowth(0) {}  // Private constructor

    double money;
    double productionRate;
    double mortalityRate;
	double crimeRate;
	int population;
	int populationGrowth;
};


#endif