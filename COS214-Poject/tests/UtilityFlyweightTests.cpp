// UtilityFlyweightTests.cpp
#include "gtest/gtest.h"
#include "../src/MockUtility.h"  // Include the mock class

TEST(UtilityFlyweightTest, InitializesCorrectly) {
    std::map<std::string, int> resources = {{"Steel", 100}, {"Concrete", 50}};
    MockUtility utility("TestUtility", 5000.0, 100, 10.0, true, 1, 20, resources);

    EXPECT_EQ(utility.getName(), "TestUtility");
    EXPECT_EQ(utility.getCost(), 5000.0);
    EXPECT_EQ(utility.getCapacity(), 100);
    EXPECT_EQ(utility.getEffectRadius(), 10.0);
    EXPECT_TRUE(utility.getOperationalStatus());
    EXPECT_EQ(utility.getLevel(), 1);
    EXPECT_EQ(utility.getResourceConsumption(), 20);
    EXPECT_EQ(utility.getResourceNeeds().at("Steel"), 100);
    EXPECT_EQ(utility.getResourceNeeds().at("Concrete"), 50);
}

TEST(UtilityFlyweightTest, ActivateDeactivate) {
    MockUtility utility("TestUtility", 5000.0, 100, 10.0, false, 1, 20, {});

    EXPECT_FALSE(utility.getOperationalStatus());
    utility.activate();
    EXPECT_TRUE(utility.getOperationalStatus());

    utility.deactivate();
    EXPECT_FALSE(utility.getOperationalStatus());
}

TEST(UtilityFlyweightTest, DisplayStatusOutputsCorrectly) {
    std::map<std::string, int> resources = {{"Steel", 100}, {"Concrete", 50}};
    MockUtility utility("TestUtility", 5000.0, 100, 10.0, true, 1, 20, resources);

    testing::internal::CaptureStdout(); // Capture the output
    utility.displayStatus();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Utility: TestUtility"), std::string::npos);
    EXPECT_NE(output.find("Status: Operational"), std::string::npos);
    EXPECT_NE(output.find("Level: 1"), std::string::npos);
    EXPECT_NE(output.find("Capacity: 100 buildings"), std::string::npos);
    EXPECT_NE(output.find("Effect Radius: 10 units"), std::string::npos);
    EXPECT_NE(output.find("Cost to Build: $5000"), std::string::npos);
    EXPECT_NE(output.find("Resource Consumption per Cycle: 20"), std::string::npos);
    EXPECT_NE(output.find("Steel: 100"), std::string::npos);
    EXPECT_NE(output.find("Concrete: 50"), std::string::npos);
}

TEST(UtilityFlyweightTest, GetTaxRevenueReturnsZero) {
    MockUtility utility("TestUtility", 5000.0, 100, 10.0, true, 1, 20, {});
    EXPECT_EQ(utility.getTaxRevenue(), 0.0);
}

TEST(UtilityFlyweightTest, ConnectBoundaryCondition) {
    MockUtility utility("TestUtility", 5000.0, 100, 10.0, true, 1, 20, {{"Steel", 100}, {"Concrete", 50}});
    
    utility.connect(10.0);  // Exactly on the boundary
    EXPECT_TRUE(utility.isConnected());

    utility.connect(10.1);  // Just outside the boundary
    EXPECT_FALSE(utility.isConnected());
}

TEST(UtilityFlyweightTest, ConnectWhenNotOperational) {
    MockUtility utility("TestUtility", 5000.0, 100, 10.0, false, 1, 20, {{"Steel", 100}, {"Concrete", 50}});
    
    utility.connect(5.0);  // Within range but not operational
    EXPECT_FALSE(utility.isConnected());

    utility.activate();
    utility.connect(5.0);  // Now operational and within range
    EXPECT_TRUE(utility.isConnected());
}

TEST(UtilityFlyweightTest, CloneCreatesIdenticalCopy) {
    std::map<std::string, int> resources = {{"Steel", 100}, {"Concrete", 50}};
    MockUtility utility("TestUtility", 5000.0, 100, 10.0, true, 1, 20, resources);

    std::unique_ptr<UtilityFlyweight> clonedUtility = utility.clone();

    // Verify that the cloned object has the same properties
    EXPECT_EQ(clonedUtility->getName(), utility.getName());
    EXPECT_EQ(clonedUtility->getCost(), utility.getCost());
    EXPECT_EQ(clonedUtility->getCapacity(), utility.getCapacity());
    EXPECT_EQ(clonedUtility->getEffectRadius(), utility.getEffectRadius());
    EXPECT_EQ(clonedUtility->getLevel(), utility.getLevel());
    EXPECT_EQ(clonedUtility->getResourceConsumption(), utility.getResourceConsumption());
    EXPECT_EQ(clonedUtility->getResourceNeeds(), utility.getResourceNeeds());

    // Verify the cloned object is a different instance
    EXPECT_NE(clonedUtility.get(), &utility);
}