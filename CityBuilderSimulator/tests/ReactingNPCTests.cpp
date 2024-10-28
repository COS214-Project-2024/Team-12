#include "gtest/gtest.h"
#include "ReactingNPCS.h"
#include "NPCManager.h"
#include "ReactingNPC.h"
#include "DonationState.h"

// Test for initial state
TEST(ReactingNPCTest, InitialStateIsNeutral) {
    ReactingNPCS npc;
    EXPECT_EQ(NPCManager::getInstance().getNeutralCount(), 1);
}

// Test for state transition from Neutral to Donation
TEST(ReactingNPCTest, TransitionNeutralToDonation) {
    ReactingNPCS npc;
    npc.changeState(new DonationState());
    EXPECT_EQ(NPCManager::getInstance().getNeutralCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getDonationCount(), 1);
}

// Test for state transition from Donation to Revolt
TEST(ReactingNPCTest, TransitionDonationToRevolt) {
    ReactingNPCS npc;
    npc.update();
    npc.cha(new RevoltState());
    EXPECT_EQ(NPCManager::getInstance().getDonationCount(), 0);
    EXPECT_EQ(NPCManager::getInstance().getRevoltCount(), 1);
}
