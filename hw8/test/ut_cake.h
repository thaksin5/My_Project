#include <gtest/gtest.h>
#include "../src/cake.h"
#include "../src/chocolate_cake.h"

class CakeTest : public ::testing::Test{
    protected:
        Cake *c1;
        Cake *c2;
        void SetUp() override;
        void TearDown() override;
};

void CakeTest::SetUp(){
    c1 = new ChocolateCake(100, 50);
    c2 = new ChocolateCake(150, 20);
}

void CakeTest::TearDown(){
    delete c1;
    delete c2;
    Cake::_totalCake = 0;
    ChocolateCake::_choco_count = 0;
} 

TEST_F(CakeTest, REGULAR_TEST){
    ASSERT_EQ(c1->get_price(), 100);
    ASSERT_EQ(c2->get_price(), 150);

    ASSERT_EQ(c1->get_sweet(), 50);
    ASSERT_EQ(c2->get_sweet(), 20);    

    ASSERT_EQ(c1->to_string(), "| ChocolateCake        |         100 |         50 |");
    ASSERT_EQ(c2->to_string(), "| ChocolateCake        |         150 |         20 |");
}

TEST_F(CakeTest, COUNT_TEST){
    ASSERT_EQ(Cake::get_total(), 2);
}