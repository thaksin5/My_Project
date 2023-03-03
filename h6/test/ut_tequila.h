#include <gtest/gtest.h>
#include "../src/alcohol.h"
#include "../src/tequila.h"

class TequilaTest : public::testing::Test{
    protected:
        Tequila a1;
        Tequila a2;
        void SetUp() override;
        void TearDown() override;
};

void TequilaTest::SetUp(){
    a1 = Tequila("mark", 130, 1.0);
    a1.dilute();

    a2 = Tequila("david", 200, 0.3);
}

void TequilaTest::TearDown(){

}

TEST_F(TequilaTest, REGULAR_TEST){
    ASSERT_EQ(a1.get_name(), "mark");
    ASSERT_EQ(a1.get_price(), 130);
    ASSERT_NEAR(a1.get_alcohol_content(), 0.95, 0.01);

    ASSERT_EQ(a2.get_name(), "david");
    ASSERT_EQ(a2.get_price(), 200);
    ASSERT_NEAR(a2.get_alcohol_content(), 0.3, 0.01);
}

TEST_F(TequilaTest, INVALID_TEST1){
    ASSERT_THROW(Tequila("", 200, 0.5), std::invalid_argument);
    ASSERT_THROW(Tequila("Peter", -200, 0.5), std::invalid_argument);
    ASSERT_THROW(Tequila("Peter", 200, 3), std::invalid_argument);
}

TEST_F(TequilaTest, INVALID_TEST2){
    Tequila a4;
    ASSERT_THROW(a4.get_name(), std::invalid_argument);
    ASSERT_THROW(a4.get_price(), std::invalid_argument);
    ASSERT_THROW(a4.get_alcohol_content(), std::invalid_argument);
    ASSERT_THROW(a4.dilute(), std::invalid_argument);
}

// operator+
TEST_F(TequilaTest, OPERATOR_TEST1){
    Tequila a3 = a1+a2;
    ASSERT_EQ(a3.get_name(), "mark");
    ASSERT_EQ(a3.get_price(), 330);
    ASSERT_NEAR(a3.get_alcohol_content(), 0.625,  0.01);

    a1 = Tequila("mark", 300, 0.4);
    a2 = Tequila("mike", 500, 0.7);
    a3 = a1+a2;
    ASSERT_EQ(a3.get_name(), "mark");
    ASSERT_EQ(a3.get_price(), 800);
    ASSERT_EQ(a3.get_alcohol_content(), 0.55);
}

// operator==
TEST_F(TequilaTest, OPERATOR_TEST2){
    Tequila a3("mike", 200, 0.3);
    Tequila a4("mike", 200, 0.3);

    ASSERT_FALSE(a1==a2);
    ASSERT_TRUE(a3==a4);
}
