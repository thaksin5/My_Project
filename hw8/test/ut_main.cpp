#include <gtest/gtest.h>
#include "ut_cake.h"
#include "ut_chocolate.h"
#include "ut_honey.h"
#include "ut_showcase.h"

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}