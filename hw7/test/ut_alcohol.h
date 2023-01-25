#include <gtest/gtest.h>
#include "../src/alcohol.h"
#include "../src/sour.h"
#include "../src/tequila.h"

class AlcoholTest : public::testing::Test{
    protected:
        Alcohol *a1;
        Alcohol *a2;
        void SetUp() override;
        void TearDown() override;
};

void AlcoholTest::SetUp(){
    a1 = new Sour("mark", 130, 1.0);
    a1->dilute();

    a2 = new Sour("david", 200, 0.3);
}

void AlcoholTest::TearDown(){
    delete a1;
    delete a2;
}

TEST_F(AlcoholTest, REGULAR_TEST){
    ASSERT_EQ(a1->get_name(), "mark");
    ASSERT_EQ(a1->get_price(), 130);
    ASSERT_NEAR(a1->get_alcohol_content(), 0.7,0.01);

    ASSERT_EQ(a2->get_name(), "david");
    ASSERT_EQ(a2->get_price(), 200);
    ASSERT_NEAR(a2->get_alcohol_content(), 0.3,0.01);
}

TEST_F(AlcoholTest, INVALID_TEST1){
    Alcohol *a3;
    ASSERT_THROW(a3 = new Sour("", 130, 1.0), std::invalid_argument);
    ASSERT_THROW(a3 = new Sour("Peter", -200, 0.5), std::invalid_argument);
    ASSERT_THROW(a3 = new Sour("Peter", 200, 3), std::invalid_argument);
}

TEST_F(AlcoholTest, INVALID_TEST2){
    Alcohol *a3;
    Tequila t1;
    a3 = &t1;
    ASSERT_THROW(a3->get_name(), std::invalid_argument);
    ASSERT_THROW(a3->get_price(), std::invalid_argument);
    ASSERT_THROW(a3->get_alcohol_content(), std::invalid_argument);
    ASSERT_THROW(a3->dilute(), std::invalid_argument);
}
