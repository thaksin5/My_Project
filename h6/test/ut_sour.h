#include <gtest/gtest.h>
#include "../src/alcohol.h"
#include "../src/sour.h"

class SourTest : public::testing::Test{
    protected:
        Sour a1;
        Sour a2;
        void SetUp() override;
        void TearDown() override;
};

void SourTest::SetUp(){
    a1 = Sour("mark", 130, 1.0);
    a1.dilute();

    a2 = Sour("david", 200, 0.3);
}

void SourTest::TearDown(){

}

TEST_F(SourTest, REGULAR_TEST){
    ASSERT_EQ(a1.get_name(), "mark");
    ASSERT_EQ(a1.get_price(), 130);
    ASSERT_NEAR(a1.get_alcohol_content(), 0.7, 0.01);

    ASSERT_EQ(a2.get_name(), "david");
    ASSERT_EQ(a2.get_price(), 200);
    ASSERT_NEAR(a2.get_alcohol_content(), 0.3, 0.01);
}

TEST_F(SourTest, INVALID_TEST1){
    ASSERT_THROW(Sour("", 200, 0.5), std::invalid_argument);
    ASSERT_THROW(Sour("Peter", -200, 0.5), std::invalid_argument);
    ASSERT_THROW(Sour("Peter", 200, 3), std::invalid_argument);
}

TEST_F(SourTest, INVALID_TEST2){
    Sour a4;
    ASSERT_THROW(a4.get_name(), std::invalid_argument);
    ASSERT_THROW(a4.get_price(), std::invalid_argument);
    ASSERT_THROW(a4.get_alcohol_content(), std::invalid_argument);
    ASSERT_THROW(a4.dilute(), std::invalid_argument);
}

// operator+
TEST_F(SourTest, OPERATOR_TEST1){
    Sour a3 = a1+a2;
    ASSERT_EQ(a3.get_name(), "mark");
    ASSERT_EQ(a3.get_price(), 330);
    ASSERT_NEAR(a3.get_alcohol_content(), 1.0,  0.5);

    a1 = Sour("mark", 300, 0.4);
    a2 = Sour("mike", 500, 0.7);
    a3 = a1+a2;
    ASSERT_EQ(a3.get_name(), "mark");
    ASSERT_EQ(a3.get_price(), 800);
    ASSERT_EQ(a3.get_alcohol_content(), 0.55);
}

// operator==
TEST_F(SourTest, OPERATOR_TEST2){
    Sour a3("mike", 200, 0.3);
    Sour a4("mike", 200, 0.3);

    ASSERT_FALSE(a1==a2);
    ASSERT_TRUE(a3==a4);
}
