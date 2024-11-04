#include <gtest/gtest.h>
#include "../COS214-Poject/src/ConcreteTaxCollector.h"
#include "../COS214-Poject/src/Government.h"
#include "../COS214-Poject/src/ResidentialBuilding.h"
#include "../COS214-Poject/src/CommercialBuilding.h"

#include "../COS214-Poject/src/PowerPlant.h"
#include "../COS214-Poject/src/WaterSupply.h"
#include "../COS214-Poject/src/WasteManagement.h"
#include "../COS214-Poject/src/SewageSystem.h"
#include "../COS214-Poject/src/House.h"
#include "../COS214-Poject/src/Malls.h"
#include "../COS214-Poject/src/Flat.h"
#include "../COS214-Poject/src/Shops.h"


// Test Tax Calculation for Residential and Commercial Buildings using ConcreteTaxCollector
TEST(TaxCalculationTest, ApplyConcreteTaxCollector) {
    // Step 1: Set up initial Government balance
    Government& gov = Government::getInstance();
    double initialMoney = gov.getMoney();
    
    // Step 2: Create buildings with prices
    std::shared_ptr<ResidentialBuilding> residentialBuilding = 
        std::make_shared<House>( nullptr, nullptr, nullptr, nullptr); // 3 bedrooms, $200,000
    std::shared_ptr<CommercialBuilding> commercialBuilding = 
        std::make_shared<Malls>(nullptr, nullptr, nullptr, nullptr); // $500,000

    // Step 3: Create ConcreteTaxCollector
    ConcreteTaxCollector taxCollector;

    // Step 4: Apply taxes by visiting each building with ConcreteTaxCollector
    residentialBuilding->accept(&taxCollector);
    commercialBuilding->accept(&taxCollector);

    // Step 5: Calculate expected tax revenue based on ConcreteTaxCollector's rates
    double expectedResidentialTax = 200000 * 0.05; // 5% of $200,000 for residential
    double expectedCommercialTax = 500000 * 0.08;  // 8% of $500,000 for commercial
    double totalExpectedTax = expectedResidentialTax + expectedCommercialTax;

    // Step 6: Check if Government money increased by expected tax revenue
    EXPECT_DOUBLE_EQ(gov.getMoney(), initialMoney + totalExpectedTax);

    // Step 7: Verify that tax was marked as paid for each building
    EXPECT_TRUE(residentialBuilding->isTaxPaid());
    EXPECT_TRUE(commercialBuilding->isTaxPaid());
}

// Test Tax Calculation with Utility-Based Adjustments
TEST(TaxCalculationTest, ApplyConcreteTaxCollectorWithUtilities) {
    // Step 1: Set up initial Government balance
    Government& gov = Government::getInstance();
    double initialMoney = gov.getMoney();
    
    // Step 2: Create utility objects
    auto powerPlant = std::make_shared<PowerPlant>();
    auto waterSupply = std::make_shared<WaterSupply>();
    auto wasteManagement = std::make_shared<WasteManagement>();
    auto sewageSystem = std::make_shared<SewageSystem>();

    // Step 3: Create buildings and assign utilities
    auto residentialBuilding = std::make_shared<Flat>( waterSupply, powerPlant, nullptr, sewageSystem);
    auto commercialBuilding = std::make_shared<Shops>( waterSupply, powerPlant, wasteManagement, sewageSystem);

    // Step 4: Apply ConcreteTaxCollector to buildings
    ConcreteTaxCollector taxCollector;
    residentialBuilding->accept(&taxCollector);
    commercialBuilding->accept(&taxCollector);

    // Step 5: Calculate expected tax with utility adjustments
    double baseResidentialTax = 200000 * 0.05; // 5% base tax for residential
    double baseCommercialTax = 500000 * 0.08;  // 8% base tax for commercial

    // Adjust residential tax based on utility coverage (3 utilities)
    double expectedResidentialTax = baseResidentialTax * 0.9; // 10% reduction for high coverage

    // Adjust commercial tax based on utility coverage (4 utilities)
    double expectedCommercialTax = baseCommercialTax * 0.85; // 15% reduction for high coverage

    double totalExpectedTax = expectedResidentialTax + expectedCommercialTax;

    // Step 6: Check if Government money increased by expected tax revenue
    EXPECT_DOUBLE_EQ(gov.getMoney(), initialMoney + totalExpectedTax);

    // Step 7: Verify that tax was marked as paid for each building
    EXPECT_TRUE(residentialBuilding->isTaxPaid());
    EXPECT_TRUE(commercialBuilding->isTaxPaid());
}


