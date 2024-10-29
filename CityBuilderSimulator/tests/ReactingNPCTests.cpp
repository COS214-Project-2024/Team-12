#include <gtest/gtest.h>
#include "../src/City/NPCs/UselessNPC/ReactingNPCS.h"
#include "../src/City/NPCs/NPCManager.h"
#include "../src/City/NPCs/UselessNPC/NeutralState.h"
#include "../src/City/NPCs/UselessNPC/DonationState.h"
#include "../src/City/NPCs/UselessNPC/RevoltState.h"
#include "../src/City/NPCs/UselessNPC/ProductiveState.h"
#include "../src/City/NPCs/UselessNPC/CrimeState.h"
#include "../src/City/NPCs/UselessNPC/NPCState.h"

// Helper to reset all counts in NPCManager for a clean test environment
void resetNPCManagerCounts() {
    NPCManager::getInstance().resetCounts();
}

// Test for initial state
TEST(ReactingNPCTest, InitialStateIsNeutral) {
    resetNPCManagerCounts();  // Reset counts before test
    ReactingNPCS npc;
    EXPECT_EQ(NPCManager::getInstance().getNeutralCount(), 1);  // Should start in Neutral
}

// Test for state transition from Neutral to Donation
TEST(ReactingNPCTest, TransitionNeutralToDonation) {
    resetNPCManagerCounts();
    ReactingNPCS npc;
    npc.changeState(new DonationState());
    
    EXPECT_EQ(NPCManager::getInstance().getNeutralCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getDonationCount(), 1);
}

// Test for state transition from Donation to Revolt
TEST(ReactingNPCTest, TransitionDonationToRevolt) {
    resetNPCManagerCounts();
    ReactingNPCS npc;
    npc.changeState(new DonationState());
    npc.changeState(new RevoltState());

    EXPECT_EQ(NPCManager::getInstance().getDonationCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getRevoltCount(), 1);
}

// Test for state transition from Neutral to Productive
TEST(ReactingNPCTest, TransitionNeutralToProductive) {
    resetNPCManagerCounts();
    ReactingNPCS npc;
    npc.changeState(new ProductiveState());

    EXPECT_EQ(NPCManager::getInstance().getNeutralCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getProductiveCount(), 1);
}

// Test for state transition from Productive to Crime
TEST(ReactingNPCTest, TransitionProductiveToCrime) {
    resetNPCManagerCounts();
    ReactingNPCS npc;
    npc.changeState(new ProductiveState());
    npc.changeState(new CrimeState());

    EXPECT_EQ(NPCManager::getInstance().getProductiveCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getCrimeCount(), 1);
}

// Test transition back to Neutral
TEST(ReactingNPCTest, TransitionAnyToNeutral) {
    resetNPCManagerCounts();
    ReactingNPCS npc;
    npc.changeState(new DonationState());
    npc.changeState(new NeutralState());

    EXPECT_EQ(NPCManager::getInstance().getDonationCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getNeutralCount(), 1);
}
