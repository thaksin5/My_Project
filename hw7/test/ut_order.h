#include <gtest/gtest.h>
#include "../src/order.h"
#include "../src/alcohol.h"
#include "../src/sour.h"

class OrderTest : public::testing::Test{
    protected:
        Alcohol *a1;
        Alcohol *a2;

        Order order_list;

        void SetUp() override;
        void TearDown() override; 
};

void OrderTest::SetUp(){
    a1 = new Sour("mark", 130, 1.0);
    a1->dilute();
    a2 = new Sour("david", 200, 0.3);      
    order_list.append_alcohol(a1);
    order_list.append_alcohol(a2);
}

void OrderTest::TearDown(){
    delete a1;
    delete a2;
}

TEST_F(OrderTest, REGUALAR_TEST){
    ASSERT_EQ(order_list.get_alcohol_count(), 2);
    ASSERT_EQ(order_list.get_total_price(), 330);
}
