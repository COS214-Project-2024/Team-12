#include "CityComposite.h"
#include "../CityComponent.h"
#include "../../NPCs/UselessNPC/NPCObserver.h"

#include <iostream>
#include <vector>
#include <string>

CityComposite::CityComposite(const std::string& name) : cityName(name), budget(0) {}

void CityComposite::add(CityComponent* zone){
	zones.push_back(zone);

    //the plan get npcManager to change the happiness level after we a change the call notify after some time to simulate new of that
    //change travelling the city
    //notify();
}

void CityComposite::remove(CityComponent* zone){
	zones.erase(std::remove(zones.begin(), zones.end(), zone), zones.end());
}

void CityComposite::displayStatus(){
	std::cout << "City: " << cityName << "\n";
        for (auto& zone : zones) {
            zone->displayStatus();
        }
}

double CityComposite::getTaxRevenue(){
	double totalTax = 0;
        for (auto& zone : zones) {
            totalTax += zone->getTaxRevenue();
        }
        return totalTax;
}

double CityComposite::getBudget() const{
    return budget;
}

// Deduct budget for buying, upgrading and repairing
bool CityComposite::deductBudget(double amount) {
    if (budget >= amount) {
        budget -= amount;
        return true;
    } else {
        std::cout << "Insufficient budget.\n";
        return false;
    }
}
void CityComposite::addBudget(double amount) {
    if(amount > 0) {
        budget += amount;
        std::cout << "Added " << amount << " to the city budget. New budget: " << budget << "\n";
    } else {
        std::cout << "Invalid amount. Budget not updated.\n";
    }
}