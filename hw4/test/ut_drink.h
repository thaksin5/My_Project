#include <gtest/gtest.h>
#include "../src/drink.h"
#include "../src/topping.h"

class DrinkTest:public::testing::Test{
    protected:
        Drink d1;
        Drink d2;

        void SetUp() override;
        void TearDown() override;
};

void DrinkTest::SetUp(){
    d1 = Drink("Signature Black Tea with Milk", 0.3, 45);
    d2 = Drink("Americano", 0, 35);
}

void DrinkTest::TearDown(){

}

TEST_F(DrinkTest, normal_test){
    //d1
    ASSERT_EQ(d1.getName(), "Signature Black Tea with Milk");
    ASSERT_NEAR(d1.getSweetnessLevel(), 0.3, 0.01);
    ASSERT_EQ(d1.getPrice(), 45);
    //d2
    ASSERT_EQ(d2.getName(), "Americano");
    ASSERT_NEAR(d2.getSweetnessLevel(), 0, 0.01);
    ASSERT_EQ(d2.getPrice(), 35);
}

TEST_F(DrinkTest, sweetnessLevel_price_test){
    d1.addTopping(Topping("Pudding", 0.15, 5));
    ASSERT_EQ(d1.getName(), "Signature Black Tea with Milk");
    ASSERT_NEAR(d1.getSweetnessLevel(), 0.45, 0.01);
    ASSERT_EQ(d1.getPrice(), 50);

    d2.addTopping(Topping("Bubble", 0.4, 10));
    ASSERT_EQ(d2.getName(), "Americano");
    ASSERT_NEAR(d2.getSweetnessLevel(), 0.4, 0.01);
    ASSERT_EQ(d2.getPrice(), 45);    
}

TEST_F(DrinkTest, copyAssignment_test){
    Drink some_drink("Black Tea", 0.2, 15);
    Drink d3;
    d3 = d2;
    ASSERT_EQ(d3.getName(), "Americano");
    ASSERT_NEAR(d3.getSweetnessLevel(), 0, 0.01);
    ASSERT_EQ(d3.getPrice(), 35);
    d3 = some_drink;
    ASSERT_EQ(d3.getName(), "Black Tea");
    ASSERT_NEAR(d3.getSweetnessLevel(), 0.2, 0.01);
    ASSERT_EQ(d3.getPrice(), 15);
}

TEST_F(DrinkTest, topping_test){
    d1.addTopping(Topping("Bubble", 0.15, 5));
    Topping topping = d1.getToppingByIndex(0);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_NEAR(topping.getSweetnessLevel(), 0.15, 0.01);
    ASSERT_EQ(topping.getPrice(), 5);
    ASSERT_EQ(d1.getToppingCount(), 1);
}

