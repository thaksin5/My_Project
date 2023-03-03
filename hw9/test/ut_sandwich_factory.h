#include <gtest/gtest.h>

#include "../src/sandwich_factory.h"
#include "../src/sweet_sandwich.h"
#include <vector>

class Factory_Test:public::testing::Test{
    protected:  
        SweetSandwich *sweet_sandwich;
        std::vector<SweetSandwich*> sweet_sandwich_set1;
        void SetUp() override;
        void TearDown() override;
};

void Factory_Test::SetUp(){
    sweet_sandwich = SandwichFactory<SweetSandwich>::create_sandwich(15, 32767);
    sweet_sandwich_set1 = SandwichFactory<SweetSandwich>::create_sandwich_array(15, 5, {33,44,55,66,99});
}

void Factory_Test::TearDown(){
    delete sweet_sandwich;
    for(int i=0; i<sweet_sandwich_set1.size(); i++){
        delete sweet_sandwich_set1[i];
    }
}

TEST_F(Factory_Test, object_test){
    ASSERT_EQ(sweet_sandwich->get_price(), 15);
    ASSERT_EQ(sweet_sandwich->get_id(), 32767);
}

TEST_F(Factory_Test, vector_test){
    ASSERT_EQ(sweet_sandwich_set1[0]->get_price(), 15);
    ASSERT_EQ(sweet_sandwich_set1[0]->get_id(), 33);

    ASSERT_EQ(sweet_sandwich_set1[1]->get_price(), 15);
    ASSERT_EQ(sweet_sandwich_set1[1]->get_id(), 44);

    ASSERT_EQ(sweet_sandwich_set1[2]->get_price(), 15);
    ASSERT_EQ(sweet_sandwich_set1[2]->get_id(), 55);

    ASSERT_EQ(sweet_sandwich_set1[3]->get_price(), 15);
    ASSERT_EQ(sweet_sandwich_set1[3]->get_id(), 66);

    ASSERT_EQ(sweet_sandwich_set1[4]->get_price(), 15);
    ASSERT_EQ(sweet_sandwich_set1[4]->get_id(), 99);

    ASSERT_THROW(SandwichFactory<SweetSandwich>::create_sandwich_array(15, -1, {33,44,55,66,99}), std::invalid_argument);
    ASSERT_THROW(SandwichFactory<SweetSandwich>::create_sandwich_array(-15, 1, {33,44,55,66,99}), std::invalid_argument);
}