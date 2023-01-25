#include <gtest/gtest.h>
#include "../src/sandwich.h"

class Sandwich_Test : public ::testing::Test{
    protected:
        Sandwich *s1;
        Sandwich *s2;
        void SetUp() override;
        void TearDown() override;
};

void Sandwich_Test::SetUp(){
    s1 = new Sandwich(60, 101);
    s2 = new Sandwich(55, 102);
}

void Sandwich_Test::TearDown(){
    delete s1;
    delete s2;
}

TEST_F(Sandwich_Test, REGULAR_TEST){
    ASSERT_EQ(s1->get_price(), 60);
    ASSERT_EQ(s2->get_price(), 55);

    ASSERT_EQ(s1->get_id(), 101);
    ASSERT_EQ(s2->get_id(), 102);
}

TEST_F(Sandwich_Test, RECORD_TEST){
    Sandwich *s3 = new Sandwich(70, 103);
    ASSERT_TRUE(Sandwich::record_has_specific_id(101));
    ASSERT_TRUE(Sandwich::record_has_specific_id(102));
    ASSERT_TRUE(Sandwich::record_has_specific_id(103));
    ASSERT_EQ(Sandwich::get_size_of_record_container(), 3);
    delete s3;
    ASSERT_FALSE(Sandwich::record_has_specific_id(103));
    ASSERT_EQ(Sandwich::get_size_of_record_container(), 2);
}