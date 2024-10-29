#include "gtest/gtest.h"
#include "../src/City/NPCs/NPCManager.h"

TEST(NPCManagerTest, SingletonInstance) {
    NPCManager& instance1 = NPCManager::getInstance();
    NPCManager& instance2 = NPCManager::getInstance();
    EXPECT_EQ(&instance1, &instance2);
}

TEST(NPCManagerTest, InitialCountsAreZero) {
    //NPCManager::getInstance().resetCounts();  // Optional: reset before testing
    EXPECT_EQ(NPCManager::getInstance().getNeutralCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getDonationCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getRevoltCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getProductiveCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getCrimeCount(), 0);
}

TEST(NPCManagerTest, IncrementAndDecrementCounts) {
    NPCManager& manager = NPCManager::getInstance();
    manager.incrementCount("DonationState");
    EXPECT_EQ(manager.getDonationCount(), 1);
    manager.decrementCount("DonationState");
    EXPECT_EQ(manager.getDonationCount(), 0);
}
