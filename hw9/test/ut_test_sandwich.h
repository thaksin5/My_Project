#include <gtest/gtest.h>

#include "../src/sandwich.h"
#include "../src/beef_sandwich.h"
#include "../src/sweet_sandwich.h"

class Test_sandwich:public::testing::Test{
    protected:
        BeefSandwich *bf1;
        BeefSandwich *bf2;           
        SweetSandwich *sw1;
        SweetSandwich *sw2;
        
        void SetUp() override;
        void TearDown() override;
};

void Test_sandwich::SetUp(){
    bf1 = new BeefSandwich(25, 0);
    bf2 = new BeefSandwich(45, 2);
    sw1 = new SweetSandwich(15, 1);
    sw2 = new SweetSandwich(25, 3);
}

void Test_sandwich::TearDown(){
    delete bf2;
    delete sw2;
}

TEST_F(Test_sandwich, test){
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(0)); // TRUE
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(1)); // TRUE
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(3)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(0)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(1)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(3)); // TRUE

    ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 2);
    ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 2);
    ASSERT_EQ(Sandwich::get_size_of_record_container(), 4);

    /* Delete some sandwich and check record */
    delete sw1;
    delete bf1;

    ASSERT_FALSE(BeefSandwich::record_has_specific_id(0));
    ASSERT_FALSE(SweetSandwich::record_has_specific_id(1));
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(2));
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(3));
    ASSERT_FALSE(Sandwich::record_has_specific_id(0));
    ASSERT_FALSE(Sandwich::record_has_specific_id(1));
    ASSERT_TRUE(Sandwich::record_has_specific_id(2));
    ASSERT_TRUE(Sandwich::record_has_specific_id(3));

    /* Check record size in sandwich */
    ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 1);
    ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 1);
    ASSERT_EQ(Sandwich::get_size_of_record_container(), 2);

    /* Check invalid */
    ASSERT_THROW(BeefSandwich(-3, 4), std::invalid_argument);
    ASSERT_THROW(SweetSandwich(-25, 5), std::invalid_argument);
}