#include <iostream>
#include <memory>
#include "ChemicalFactory.h"
#include "MetalFactory.h"
#include "PlantFactory.h"
#include "StoneFactory.h"
#include "Gold.h"
#include "Diamonds.h"
#include "Oil.h"
#include "Coal.h"
#include "Wood.h"
#include "Stone.h"
#include "Steel.h"
#include "Concrete.h"
#include "../CityComponent.h"

int main() {
    // Create factory instances
    std::unique_ptr<ResourceFactory> chemicalFactory = std::make_unique<ChemicalFactory>();
    std::unique_ptr<ResourceFactory> metalFactory = std::make_unique<MetalFactory>();
    std::unique_ptr<ResourceFactory> plantFactory = std::make_unique<PlantFactory>();
    std::unique_ptr<ResourceFactory> stoneFactory = std::make_unique<StoneFactory>();

    // Use factories to create income resources
    auto incomeResource1 = chemicalFactory->createIncomeR(100);
    auto incomeResource2 = metalFactory->createIncomeR(50);
    auto incomeResource3 = plantFactory->createIncomeR(200);
    auto incomeResource4 = stoneFactory->createIncomeR(150);

    // Display income resources' statuses
    std::cout << "Income Resources:\n";
    incomeResource1->displayStatus();
    incomeResource2->displayStatus();
    incomeResource3->displayStatus();
    incomeResource4->displayStatus();

    // Use factories to create construction resources
    auto constructionResource1 = chemicalFactory->createConstructionR(300);
    auto constructionResource2 = metalFactory->createConstructionR(120);
    auto constructionResource3 = plantFactory->createConstructionR(80);
    auto constructionResource4 = stoneFactory->createConstructionR(500);

    // Display construction resources' statuses
    std::cout << "\nConstruction Resources:\n";
    constructionResource1->displayStatus();
    constructionResource2->displayStatus();
    constructionResource3->displayStatus();
    constructionResource4->displayStatus();

    // Demonstrate direct creation and display of specific resource types
    std::cout << "\nDirectly Created Resources:\n";
    Gold gold(50, 100.0);
    Diamonds diamonds(30, 300.0);
    Oil oil(40, 50.0);
    Coal coal(70, 20.0);
    Wood wood(200, 15);
    Stone stone(150, 10);
    Steel steel(100, 25);
    Concrete concrete(300, 12);

    gold.displayStatus();
    diamonds.displayStatus();
    oil.displayStatus();
    coal.displayStatus();
    wood.displayStatus();
    stone.displayStatus();
    steel.displayStatus();
    concrete.displayStatus();

    return 0;
}
