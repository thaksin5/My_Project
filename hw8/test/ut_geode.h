#include <gtest/gtest.h>
#include "../src/geode_cake.h"

class GeodeTest:public::testing::Test{
    protected:
        GeodeCake geode1;
        GeodeCake geode2;
        void SetUp() override;
        void TearDown() override;
};

void GeodeTest::SetUp(){
    geode1 = GeodeCake(100, 50);
    geode2 = GeodeCake(150, 20);
}

void GeodeTest::TearDown(){
}

TEST_F(GeodeTest, REGULAR_TEST){
    ASSERT_EQ(geode1.get_price(), 100);
    ASSERT_EQ(geode2.get_price(), 150);

    ASSERT_EQ(geode1.get_sweet(), 50);
    ASSERT_EQ(geode2.get_sweet(), 20);    

    ASSERT_EQ(geode1.to_string(), "| GeodeCake        |         100 |         50 |");
    ASSERT_EQ(geode2.to_string(), "| GeodeCake        |         150 |         20 |");
}

TEST_F(GeodeTest, COUNT_TEST){
    ASSERT_EQ(Cake::get_total(), 2);
    ASSERT_EQ(GeodeCake::get_count(), 2);
}