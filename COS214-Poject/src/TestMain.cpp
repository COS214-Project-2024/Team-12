#include "CityComponent.h"
#include "CityComposite.h"
#include "ZoneComposite.h"
#include "CommercialBuilding.h"
#include "ResidentialBuilding.h"
#include "Industry.h"
#include "Node.h"
#include "MapGrid.h"
#include "Transport.h"
#include "House.h"
#include "Estate.h"
#include "Roads.h"
#include "Trains.h"
#include "Office.h"
#include "AdvancedTechnologyDecorator.h"
#include "ChemicalFactory.h"
#include "Coal.h"
#include "CollectionStrategy.h"
#include "CommercialFactory.h"
#include "Concrete.h"
#include "concreteTaxCollector.h"
#include "ConstructionResourceProduct.h"

#include <iostream>


int main() {
    // Step 1: Initialize a MapGrid for the city layout
    MapGrid cityMap(10, 10);  // A 10x10 map grid

    // Step 2: Create the CityComposite to hold zones
    CityComposite city("MyCity", &cityMap);

    // Step 3: Define Zones with Specific Boundaries
    ZoneComposite residentialZone("Residential", 1, 3, 1, 3); // Residential zone from (1,1) to (3,3)
    ZoneComposite CommercialZone("Commercial", 5, 7, 5, 7);    // Industrial zone from (5,5) to (7,7)

    // Step 4: Add Zones to the City and Place Them on the Map
    city.add(&residentialZone, 2, 2);  // Place residential zone at (2,2)
    city.add(&CommercialZone, 6, 6);   // Place industrial zone at (6,6)

    // Step 5: Add Buildings within Each Zone at Specific Coordinates
	ResidentialBuilding* Res_house = new House();
    CityComponent* house = Res_house;

    //BuildingComponent apartment("Residential"); //might consider doing it like this

	ResidentialBuilding* Res_estate = new Estate();
	CityComponent* estate = Res_estate;

    //BuildingComponent factory("Industrial");

	CommercialBuilding* Com_office = new Office();
	CityComponent* office = Com_office;

    residentialZone.add(house, 2, 2);       // Place house at (2,2) within residential zone
    residentialZone.add(estate, 3, 3);   // Place apartment at (3,3) within residential zone
    CommercialZone.add(office, 6, 6);      // Place factory at (6,6) within industrial zone

    // Step 6: Check Adjacency and Connect Zones with Transport if Necessary
    Location residentialLoc = residentialZone.getLocation();
    Location industrialLoc = CommercialZone.getLocation();

    if (!cityMap.isAdjacent(residentialLoc, industrialLoc)) {
        // Zones are not adjacent, so connect them with a transportation route
        std::cout << "Connecting residential and industrial zones with transport...\n";
        
        // Connect with a road link (lower speed, lower cost)
        city.connectZones(&residentialZone, &CommercialZone, std::make_unique<Roads>());

        // Optionally, connect with a faster train link as well
        city.connectZones(&residentialZone, &CommercialZone, std::make_unique<Trains>());
    } else {
        std::cout << "Residential and industrial zones are adjacent. No transport needed.\n";
    }

    // Step 7: Display the City Layout and Zone Details
    city.displayStatus();

    return 0;
}
