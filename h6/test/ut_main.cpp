#include <gtest/gtest.h>
#include "ut_sour.h"
#include "ut_tequila.h"
#include "ut_alcohol.h"

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}