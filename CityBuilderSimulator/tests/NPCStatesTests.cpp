#include "gtest/gtest.h"
#include "../src/City/Government.h"
#include "../src/City/NPCs/UselessNPC/DonationState.h"
#include "../src/City/NPCs/UselessNPC/RevoltState.h"

// Test DonationState handle effect
TEST(DonationStateTest, IncreasesCityMoney) {
    //Government::getInstance().resetMoney();  // Optional: reset before testing
    DonationState donation;
    donation.handle();
    EXPECT_GT(Government::getInstance().getMoney(), 0);  // Check money increase
}

// Test RevoltState handle effect
TEST(RevoltStateTest, DecreasesProduction) {
    //Government::getInstance().resetProduction();  // Optional: reset before testing
    RevoltState revolt;
    revolt.handle();
    EXPECT_LT(Government::getInstance().getProductionRate(), 1.0);  // Check production decrease
}
