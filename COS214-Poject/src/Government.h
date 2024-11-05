#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <string>
#include <map>

/**
 * @brief The Government class manages the state and functionality of the government in the simulation.
 * 
 * This class follows the Singleton design pattern, ensuring only one instance exists throughout the application.
 */
class Government {
public:
    /**
     * @brief Retrieves the singleton instance of the Government class.
     * 
     * @return Government& Reference to the singleton instance.
     */
    static Government& getInstance() {
        static Government instance;  // Only created once
        return instance;
    }

    // Delete copy constructor and assignment operator to prevent copies
    Government(const Government&) = delete;
    Government& operator=(const Government&) = delete;

    /**
     * @brief Displays the current statistics of the government.
     */
    void displayGovernmentStats();

    // Government functionality

    /**
     * @brief Adds a specified amount of money to the government funds.
     * 
     * @param amount The amount of money to add.
     */
    void addMoney(double amount);

    /**
     * @brief Reduces the government funds by a specified amount.
     * 
     * @param amount The amount of money to reduce.
     */
    void reduceMoney(double amount);

    /**
     * @brief Reduces the production rate by a specified factor.
     * 
     * @param factor The factor by which to reduce production.
     */
    void reduceProduction(double factor);

    /**
     * @brief Increases the production rate by a specified factor.
     * 
     * @param factor The factor by which to increase production.
     */
    void increaseProduction(double factor);

    /**
     * @brief Increases the crime rate by a specified factor.
     * 
     * @param factor The factor by which to increase crime.
     */
    void increaseCrimeRate(double factor);

    /**
     * @brief Gets the current amount of money the government has.
     * 
     * @return double The current money.
     */
    double getMoney() const;

    /**
     * @brief Gets the current production rate of the government.
     * 
     * @return double The current production rate.
     */
    double getProductionRate() const;

    /**
     * @brief Sets the production rate of the government.
     * 
     * @param rate The new production rate.
     */
    void setProductionRate(double rate);

    /**
     * @brief Gets the current mortality rate.
     * 
     * @return double The current mortality rate.
     */
    double getMortalityRate() const;

    /**
     * @brief Gets the current crime rate.
     * 
     * @return double The current crime rate.
     */
    double getCrimeRate() const;

    /**
     * @brief Sets the crime rate.
     * 
     * @param rate The new crime rate.
     */
    void setCrimeRate(int rate);

    /**
     * @brief Gets the current population growth rate.
     * 
     * @return int The current population growth.
     */
    int getPopulationGrowth() const;

    /**
     * @brief Sets the population growth rate.
     * 
     * @param growth The new population growth.
     */
    void setPopulationGrowth(int growth);

    /**
     * @brief Gets the current population of the city.
     * 
     * @return int The current population.
     */
    int getPopulation() const;

    /**
     * @brief Updates the population based on various factors.
     */
    void updatePopulation();

    /**
     * @brief Sets the tax rate.
     * 
     * @param rate The new tax rate.
     */
    void setTax(double rate);

    /**
     * @brief Increases the employment rate by a specified amount.
     * 
     * @param rate The amount to increase the employment rate.
     */
    void increaseEmploymentRate(double rate);

    /**
     * @brief Sets the amount of a specified building type.
     * 
     * @param type The type of building.
     * @param amount The amount of the building type to set.
     */
    void setBuildingAmount(std::string type, int amount);

    /**
     * @brief Gets the amount of a specified building type.
     * 
     * @param type The type of building.
     * @return int The amount of the specified building type.
     */
    int getBuildingAmount(std::string type);

    /**
     * @brief Decreases the population by a specified amount.
     * 
     * @param amount The amount to decrease the population.
     */
    void decreasePopulation(int amount);

    // Resource Tracking

    /**
     * @brief Adds a processed resource to the government's records.
     * 
     * @param resourceName The name of the resource.
     * @param amount The amount of the resource.
     * @param value The market value of the resource.
     */
    void addProcessedResource(const std::string& resourceName, int amount, double value);

    /**
     * @brief Increases the population by a specified amount.
     * 
     * @param amount The amount to increase the population.
     */
    void increasePopulation(int amount);

    /**
     * @brief Increments the pollution level by a specified amount.
     * 
     * @param amount The amount to increment pollution.
     */
    void incrementPollutionLevel(int amount);

    /**
     * @brief Decrements the pollution level by a specified amount.
     * 
     * @param amount The amount to decrement pollution.
     */
    void decrementPollutionLevel(int amount);

    /**
     * @brief Gets the current pollution level.
     * 
     * @return int The current pollution level.
     */
    int getPollutionLevel();

    /**
     * @brief Calculates the tax revenue based on current settings.
     */
    void calculateTax();

    /**
     * @brief Gets the current income tax rate.
     * 
     * @return double The current income tax rate.
     */
    double getIncomeTaxRate();

    /**
     * @brief Constructs a Government object with default values.
     * 
     * This constructor is private to ensure the singleton pattern is maintained.
     */
    Government() : money(10000), productionRate(1.0), mortalityRate(0.01), crimeRate(0.00), population(0), populationGrowth(0), EMPLOYMENT_RATE(0) {}  // Private constructor

private:
    double money;                ///< Current money of the government
    double productionRate;       ///< Current production rate
    double mortalityRate;        ///< Current mortality rate
    double crimeRate;            ///< Current crime rate
    int population;              ///< Current population of the city
    int populationGrowth;        ///< Current population growth rate

    // Income tax stuff
    double incomeTax;           ///< Current income tax
    double incomeTaxRate;       ///< Current income tax rate

    // Employment rate
    double EMPLOYMENT_RATE;     ///< Current employment rate

    // Counts of building types
    int publicServiceAmount;     ///< Number of public service buildings
    int utilityAmount;           ///< Number of utility buildings
    int residentialAmount;       ///< Number of residential buildings

    std::map<std::string, int> processedResources;  ///< Store processed resources
    std::map<std::string, double> resourceValues;   ///< Store resource market values

    // Pollution level
    int pollutionLevel;          ///< Current pollution level
};

#endif
