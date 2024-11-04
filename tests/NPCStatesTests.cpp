#include "gtest/gtest.h"
#include "../COS214-Poject/src/Government.h"
#include "../COS214-Poject/src/DonationState.h"
#include "../COS214-Poject/src/RevoltState.h"
#include "../COS214-Poject/src/ReactingNPCS.h"

// Test DonationState handle effect
TEST(DonationStateTest, IncreasesCityMoney) {
    //Government::getInstance().resetMoney();  // Optional: reset before testing
    DonationState donation;
    donation.handle();
    EXPECT_GT(Government::getInstance().getMoney(), 0);  // Check money increase
}


// Test RevoltState handle effect on production
/* TEST(RevoltStateTest, DecreasesProduction) {
    // Reset the production rate to a known initial value
    Government::getInstance().setProductionRate(1.0);

    // Create a new NPC and force it into RevoltState
    ReactingNPCS npc;
    RevoltState* revoltState = new RevoltState(true);
    npc.changeState(revoltState);  // Force state to RevoltState

    // Call handle directly to apply the revolt effect
    revoltState->handle();

    // Verify that the production rate has decreased
    EXPECT_LT(Government::getInstance().getProductionRate(), 1.0)
        << "Expected production rate to decrease due to revolt.";
} */



