#include <gtest/gtest.h>
#include "../src/chocolate_cake.h"

class ChocoTest:public::testing::Test{
    protected:
        ChocolateCake choco1;
        ChocolateCake choco2;
        void SetUp() override;
        void TearDown() override;
};

void ChocoTest::SetUp(){
    choco1 = ChocolateCake(100, 50);
    choco2 = ChocolateCake(150, 20);
}

void ChocoTest::TearDown(){
}

TEST_F(ChocoTest, REGULAR_TEST){
    ASSERT_EQ(choco1.get_price(), 100);
    ASSERT_EQ(choco2.get_price(), 150);

    ASSERT_EQ(choco1.get_sweet(), 50);
    ASSERT_EQ(choco2.get_sweet(), 20);    

    ASSERT_EQ(choco1.to_string(), "| ChocolateCake        |         100 |         50 |");
    ASSERT_EQ(choco2.to_string(), "| ChocolateCake        |         150 |         20 |");
}

TEST_F(ChocoTest, COUNT_TEST){
    ASSERT_EQ(Cake::get_total(), 2);
    ASSERT_EQ(ChocolateCake::get_count(), 2);
}