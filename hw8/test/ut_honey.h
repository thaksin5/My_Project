#include <gtest/gtest.h>
#include "../src/honey_cake.h"

class HoneyTest:public::testing::Test{
    protected:
        HoneyCake honey1;
        HoneyCake honey2;
        void SetUp() override;
        void TearDown() override;
};

void HoneyTest::SetUp(){
    honey1 = HoneyCake(100, 50);
    honey2 = HoneyCake(150, 20);
}

void HoneyTest::TearDown(){
}

TEST_F(HoneyTest, REGULAR_TEST){
    ASSERT_EQ(honey1.get_price(), 100);
    ASSERT_EQ(honey2.get_price(), 150);

    ASSERT_EQ(honey1.get_sweet(), 50);
    ASSERT_EQ(honey2.get_sweet(), 20);    

}

TEST_F(HoneyTest, COUNT_TEST){
    ASSERT_EQ(Cake::get_total(), 2);
    ASSERT_EQ(HoneyCake::get_count(), 2);
}