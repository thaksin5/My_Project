#include <gtest/gtest.h>
#include <vector>

#include "../src/algorithm.h"
#include "../src/order.h"
#include "../src/alcohol.h"
#include "../src/sour.h"

class AlgorithmTest:public::testing::Test{
    protected:
    Alcohol *a1;
    Alcohol *a2;
    Alcohol *a3;
    std::vector<Alcohol*> order_list1;
    
    Alcohol *a4;
    Alcohol *a5;
    Alcohol *a6;
    std::vector<Alcohol*> order_list2;

    Alcohol *a7;
    Alcohol *a8;
    Alcohol *a9;
    std::vector<Alcohol*> order_list3;

    Alcohol *a10;
    Alcohol *a11;
    Alcohol *a12;
    std::vector<Alcohol*> order_list4;

    void SetUp() override;
    void TearDown() override; 
};

void AlgorithmTest::SetUp(){
    a1 = new Sour("mark", 130, 1.0);
    a1->dilute();
    a2 = new Sour("david", 200, 0.3);  
    a3 = new Sour("dave", 155, 0.4);
    // ----------------------------------------------
    a4 = new Sour("Mark", 130, 0.4);
    a5 = new Sour("John", 200, 0.4);
    a6 = new Sour("William", 150, 0.2);
    // ----------------------------------------------
    a7 = new Sour("sour1", 130, 0.2);
    a8 = new Sour("sour2", 200, 0.2);
    a9 = new Sour("sour3", 150, 0.8);
    //------------------------------------------------
    a10 = new Sour("sour1", 130, 0.8);
    a11 = new Sour("sour2", 200, 0.8);
    a12 = new Sour("sour3", 150, 0.2);

    order_list1.push_back(a1);
    order_list1.push_back(a2);
    order_list1.push_back(a3);

    order_list2.push_back(a4);
    order_list2.push_back(a5);
    order_list2.push_back(a6);

    order_list3.push_back(a7);
    order_list3.push_back(a8);
    order_list3.push_back(a9);

    
    order_list4.push_back(a10);
    order_list4.push_back(a11);
    order_list4.push_back(a12);
}

void AlgorithmTest::TearDown(){
    delete a1;
    delete a2;
    delete a3;

    delete a4;
    delete a5;
    delete a6;

    delete a7;
    delete a8;
    delete a9;

    delete a10;
    delete a11;
    delete a12;
}

TEST_F(AlgorithmTest, SORT_CONTENT){
    sort_alcohol_by_content(order_list1);
    ASSERT_TRUE(order_list1[0] == a2);
    ASSERT_TRUE(order_list1[1] == a3);
    ASSERT_TRUE(order_list1[2] == a1);

    sort_alcohol_by_content(order_list2);
    ASSERT_TRUE(order_list2[0] == a6);
    ASSERT_TRUE(order_list2[1] == a5);
    ASSERT_TRUE(order_list2[2] == a4);   
}

TEST_F(AlgorithmTest, SORT_NAME){
    sort_alcohol_by_name(order_list1);
    ASSERT_TRUE(order_list1[0] == a3);
    ASSERT_TRUE(order_list1[1] == a2);
    ASSERT_TRUE(order_list1[2] == a1);

    sort_alcohol_by_name(order_list2);
    ASSERT_TRUE(order_list2[0] == a5);
    ASSERT_TRUE(order_list2[1] == a4);
    ASSERT_TRUE(order_list2[2] == a6);
}

TEST_F(AlgorithmTest, GET_MAX_TEST){
    ASSERT_TRUE(get_greatest_content_of_alcohol(order_list1) == a1);
    ASSERT_TRUE(get_greatest_content_of_alcohol(order_list4) == a11);
}

TEST_F(AlgorithmTest, GET_MIN_TEST){
    ASSERT_TRUE(get_smallest_content_of_alcohol(order_list1) == a2);
    ASSERT_TRUE(get_smallest_content_of_alcohol(order_list3) == a7);
}
