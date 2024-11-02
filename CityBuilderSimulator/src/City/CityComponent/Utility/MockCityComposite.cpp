#include "MockCityComposite.h"

MockCityComposite::MockCityComposite(const std::string& name, double initialBudget) : CityComposite(name), budget(initialBudget){}

bool MockCityComposite::deductBudget(double amount) {
    if (budget >= amount) {
        budget -= amount;
        return true;
    }
    return false;
}

double MockCityComposite::getBudget() const {
    return budget;
}

void MockCityComposite::addBudget(double amount) {
    budget += amount;
}

void MockCityComposite::setBudget(double amount) {
    budget = amount;
}
