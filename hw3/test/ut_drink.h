#include <gtest/gtest.h>
#include "../src/drink.h"
#include <string.h>

class DrinkTest : public ::testing::Test{
    protected:
        Drink d1;
        Drink d2;
        std::string name1;
        std::string name2;

        void SetUp() override;
        void TearDown() override;
};

void DrinkTest::SetUp(){
    double sweet1 = 0.4;
    double sweet2 = 0.1;
    name1 = "Signature Black Tea with Milk";
    name2 = "Americano";
    d1 = Drink(name1, sweet1);
    d2 = Drink(name2, sweet2);
}

void DrinkTest::TearDown(){
    
}   

// check Drink::Drink() work correctly.
TEST_F(DrinkTest, drinkTest1){
    ASSERT_EQ(d1.getName(), "Signature Black Tea with Milk");
    ASSERT_NEAR(d1.getSweetnessLevel(), 0.4, 0.01);
}
TEST_F(DrinkTest, drinkTest2){
    Drink d3;
    ASSERT_EQ(d2.getName(), "Americano");
    ASSERT_NEAR(d2.getSweetnessLevel(), 0.1, 0.01);
    ASSERT_THROW(d3.getName(), std::string);
}

// check Drink::getName work correctly.
TEST_F(DrinkTest, nameTest1){
    ASSERT_EQ(d1.getName(), "Signature Black Tea with Milk");
    ASSERT_EQ(d2.getName(), "Americano");
}
TEST_F(DrinkTest, nameTest2){
    Drink drink1("", 0.5);
    ASSERT_THROW(drink1.getName(), std::string);
    ASSERT_THROW(Drink drink2("tea", 0.5), std::string);
}

// check Drink::getToppingCount work correctly.
TEST_F(DrinkTest, topping_count_1){
    d1.addTopping("Pudding");
    d1.addTopping("Bubble");
    ASSERT_EQ(d1.getToppingCount(), 2);
}
TEST_F(DrinkTest, topping_count_2){
    d2.addTopping("Pudding");
    d2.addTopping("Bubble");
    d2.addTopping("Bubble");
    d2.addTopping("Bubble");
    d2.addTopping("Bubble");
    d2.addTopping("Bubble");
    d2.addTopping("Bubble");

    ASSERT_EQ(d2.getToppingCount(), 7);
}
TEST_F(DrinkTest, topping_count){
    d1.addTopping("Pudding");
    d1.addTopping("Cookie");
    d1.addTopping("Pudding");
    d1.addTopping("Cookie");
    ASSERT_THROW(d1.getToppingByIndex(4), std::string);
}
