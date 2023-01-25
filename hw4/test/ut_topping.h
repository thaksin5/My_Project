#include <gtest/gtest.h>
#include "../src/topping.h"
#include <cmath>

class ToppingTest: public ::testing::Test{
    protected:
        Topping t1;
        Topping t2;

        void SetUp() override;
        void TearDown() override;
};

void ToppingTest::SetUp(){
    t1 = Topping("Bubble", 0.4, 5);
}

void ToppingTest::TearDown(){

}

TEST_F(ToppingTest, normal_test){
    ASSERT_EQ(t1.getName(), "Bubble");
    ASSERT_EQ(t1.getSweetnessLevel(), 0.4);
    ASSERT_EQ(t1.getPrice(), 5);
}

TEST_F(ToppingTest, copyAssignment_test){
    Topping t2;
    t2 = t1;
    ASSERT_EQ(t2.getName(), "Bubble");
    ASSERT_EQ(t2.getSweetnessLevel(), 0.4);
    ASSERT_EQ(t2.getPrice(), 5);
}

TEST_F(ToppingTest, error_test){
    ASSERT_THROW(Topping("Bub", 0.4, 5), std::string);
    ASSERT_THROW(Topping("Bubble", -0.1, 5), std::string);
    ASSERT_THROW(Topping("Bubble", 0.4, -5), std::string);
}


