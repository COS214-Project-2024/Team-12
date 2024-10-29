#include "City/CityComponent/CityComponent.h"
#include "City/NPCs/NPCManager.h"
#include "City/Government.h"

#include "City/CityComponent/Commercial/CommercialZoneComposite.h"
#include "City/CityComponent/Industrial/IndustrialZoneComposite.h"
#include "City/CityComponent/Residential/ResidentialZoneComposite.h"


#include "City/CityComponent/Commercial/CommercialBuilding.h"
#include "City/CityComponent/Commercial/Malls.h"
#include "cITY/CityComponent/Commercial/Office.h"
#include "City/CityComponent/Commercial/Shops.h"

#include "City/CityComponent/Industrial/CrystalCraftIndustry.h"
#include "City/CityComponent/Industrial/Industry.h"
#include "City/CityComponent/Industrial/MetalWorkFacility.h"
#include "City/CityComponent/Industrial/PetroChemicalFacility.h"
#include "City/CityComponent/Industrial/WoodAndCoalPlant.h"

#include "City/CityComponent/Landmark/CulturalCenter.h"
#include "City/CityComponent/Landmark/LandMark.h"
#include "City/CityComponent/Landmark/Monument.h"
#include "City/CityComponent/Landmark/Park.h"

#include "City/CityComponent/Residential/Estate.h"
#include "City/CityComponent/Residential/Flat.h"
#include "City/CityComponent/Residential/House.h"
#include "City/CityComponent/Residential/ResidentialBuilding.h"
#include "City/CityComponent/Residential/Townhouse.h"

#include "City/CityComponent/PublicService/FireStation.h"
#include "City/CityComponent/PublicService/Hospital.h"
#include "City/CityComponent/PublicService/PoliceStation.h"
#include "City/CityComponent/PublicService/PublicService.h"
#include "City/CityComponent/PublicService/School.h"

#include "City/CityComponent/Resources/ChemicalFactory.h"
#include "City/CityComponent/Resources/Coal.h"
#include "City/CityComponent/Resources/Concrete.h"
#include "City/CityComponent/Resources/ConstructionResourceProduct.h"
#include "City/CityComponent/Resources/Diamonds.h"
#include "City/CityComponent/Resources/Gold.h"

#include "City/CityComponent/Transport/Airports.h"
#include "City/CityComponent/Transport/DeliveryTruck.h"
#include "City/CityComponent/Transport/PublicTransit.h"
#include "City/CityComponent/Transport/Roads.h"
#include "City/CityComponent/Transport/Trains.h"
#include "City/CityComponent/Transport/Transport.h"

#include "City/CityComponent/Utility/AdvancedTechnologyDecorator.h"
#include "City/CityComponent/Utility/GreenTechnologyDecorator.h"
#include "City/CityComponent/Utility/MockUtility.h"
#include "City/CityComponent/Utility/PowerPlant.h"
#include "City/CityComponent/Utility/SewageSystem.h"
#include "City/CityComponent/Utility/UtilityDecorator.h"
#include "City/CityComponent/Utility/UtilityFactory.h"
#include "City/CityComponent/Utility/UtilityFlyweight.h"
#include "City/CityComponent/Utility/WasteManagement.h"
#include "City/CityComponent/Utility/WaterSupply.h"

#include "City/NPCs/NPCManager.h"

#include "City/NPCs/UselessNPC/NPCObserver.h"
#include "City/NPCs/UselessNPC/CrimeState.h"
#include "City/NPCs/UselessNPC/DonationState.h"
#include "City/NPCs/UselessNPC/NeutralState.h"
#include "City/NPCs/UselessNPC/NPCState.h"
#include "City/NPCs/UselessNPC/ProductiveState.h"
#include "City/NPCs/UselessNPC/ReactingNPCS.h"
#include "City/NPCs/UselessNPC/RevoltState.h"

int main() {
    // Step 1: Create a City Composite and Residential Zone Composite
    CityComposite myCity("MyCity");

    // Attempt to add Residential Zone and Residential Building directly to City
    ResidentialZoneComposite* residentialZone = new ResidentialZoneComposite(0.05);
    CityComponent* residentialBuilding = new House(); // Assuming ResidentialBuilding is defined

    // Step 2: Test adding residential buildings directly to the city
    std::cout << "Adding a residential building directly to the city:\n";
    myCity.add(residentialBuilding);  // Should be allowed only if not in resource site
    myCity.displayStatus();

    // Step 3: Test adding residential zones to the city and buildings within the zone
    std::cout << "\nAdding a residential zone to the city:\n";
    myCity.add(residentialZone);  // Should be allowed
    myCity.displayStatus();

    std::cout << "\nAdding buildings to the residential zone:\n";
    residentialZone->add(residentialBuilding);  // Should work, as it's a building

    // Try adding another residential zone within the residential zone (should not be allowed)
    ResidentialZoneComposite* subResidentialZone = new ResidentialZoneComposite(0.03);
    std::cout << "\nAttempting to add a residential zone within another residential zone:\n";
    residentialZone->add(subResidentialZone);  // Should not be allowed

    // Step 4: Display city structure to confirm correct setup
    myCity.displayStatus();

    // Clean up
    delete residentialZone;
    delete residentialBuilding;
    delete subResidentialZone;

    return 0;
}