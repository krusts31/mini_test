#define CATCH_CONFIG_MAIN 
#include "catch_amalgamated.hpp"

int ret_2()
{
    return (2);
}

namespace tests
{
    TEST_CASE("Test 1", "1")
    {
        CHECK(ret_2() == 2);
    }
}
