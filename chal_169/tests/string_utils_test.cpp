// string_utils_test.cpp
// Build using: g++ -ggdb -std=c++0x -Wall -o su_test string_utils_test.cpp -lboost_unit_test_framework
#include <boost/test/minimal.hpp>
#include "../string_utils.h"

int test_main(int, char *[]) {

    std::vector<int> vi = {1, 2, 3, 4};
    std::string s = string_utils::fmt_as_list(vi);

    BOOST_CHECK(s == "1, 2, 3, 4");

    return 0;
}