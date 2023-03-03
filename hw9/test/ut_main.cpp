#include <gtest/gtest.h>
#include "ut_sandwich.h"
#include "ut_test_sandwich.h"
#include "ut_sandwich_factory.h"

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}