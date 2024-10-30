#include "CityComposite.h"
#include "../CityComponent.h"
#include "../../NPCs/UselessNPC/NPCObserver.h"
#include "../../Government.h"

#include <iostream>
#include <vector>
#include <string>

CityComposite::CityComposite(const std::string& name) : cityName(name), budget(0) {}

void CityComposite::add(CityComponent* zone){
	zones.push_back(zone);

    std::string type = zone->getBuildingType();
    if(type == "Residential Building"){
        Government::getInstance().setBuildingAmount("Residential",1);
    }else if(type == "Utility"){
        Government::getInstance().setBuildingAmount("Utility",1);
    }else if(type == "Public Service"){
        Government::getInstance().setBuildingAmount("Public Service",1);
    }
    /* 
     */

    //the plan get npcManager to change the happiness level after we a change the call notify after some time to simulate new of that
    //change travelling the city

    //check if there is enough 
    checkCityConditions();

    notify();
}

void CityComposite::remove(CityComponent* zone){
	zones.erase(std::remove(zones.begin(), zones.end(), zone), zones.end());
}

void CityComposite::displayStatus(){
	std::cout << "City: " << cityName << "\n";
        for (auto& zone : zones) {
            zone->displayStatus();
        }

        Government::getInstance().displayGovernmentStats();
}


double CityComposite::getBudget() const{
    return Government::getInstance().getMoney();
}

// Deduct budget for buying, upgrading and repairing
bool CityComposite::deductBudget(double amount) {
    if (Government::getInstance().getMoney() >= amount) {
        Government::getInstance().reduceMoney(amount);
        return true;
    } else {
        std::cout << "Insufficient budget.\n";
        return false;
    }
}
void CityComposite::addBudget(double amount) {
    if(amount > 0) {
        Government::getInstance().addMoney(amount);
    } else {
        std::cout << "Invalid amount. Budget not updated.\n";
    }
}

bool CityComposite::checkCityConditions(){
    int publicServiceBuildings = Government::getInstance().getBuildingAmount("Public Service");
    int residentialBuildings = Government::getInstance().getBuildingAmount("Residential") ;
    int utilityBuildings = Government::getInstance().getBuildingAmount("Utility");

    if((publicServiceBuildings >= 5 && publicServiceBuildings <= 7) && (residentialBuildings >= 3 && residentialBuildings <= 10) && (utilityBuildings >= 2 && utilityBuildings <= 5)){
        Government::getInstance().setPopulationGrowth(5);
        return true;
    }
    else if((publicServiceBuildings >= 8 && publicServiceBuildings <= 12) && (residentialBuildings >= 6 && residentialBuildings <= 15) && (utilityBuildings >= 8 && utilityBuildings <= 12)){
        Government::getInstance().setPopulationGrowth(10);
        return true;
    }
}

