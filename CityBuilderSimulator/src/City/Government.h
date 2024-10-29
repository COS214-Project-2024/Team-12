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
    void reduceProduction(double factor);
    void increaseProduction(double factor);
    void increaseCrimeRate(double factor);

    double getMoney() const;
    double getProductionRate() const;
	void setProductionRate(double rate);
    double getMortalityRate() const;
	double getCrimeRate() const;
	int getPopulationGrowth() const;
	void setPopulationGrowth(int growth);
	int getPopulation() const;
    void updatePopulation();

	void setTax(double rate);
	void increaseEmploymentRate(double rate);
    Government() : money(10000), productionRate(1.0), mortalityRate(0.01), crimeRate(0.00), population(0), populationGrowth(0), EMPLOYMENT_RATE(0) {}  // Private constructor

private:

    double money;
    double productionRate;
    double mortalityRate;
	double crimeRate;
	int population;
	int populationGrowth;
	double incomeTax;
	double incomeTaxRate;
	double EMPLOYMENT_RATE;

	void calculateTax();
};


#endif