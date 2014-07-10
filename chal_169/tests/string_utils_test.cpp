// string_utils_test.cpp
// Build using: g++ -ggdb -std=c++0x -Wall -o su_test string_utils_test.cpp -lboost_unit_test_framework
#include "../string_utils.h"
#define BOOST_TEST_MODULE string_utils_test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(su_test) {

    std::vector<int> vi = {1, 2, 3, 4};
    std::string s = string_utils::fmt_as_list(vi);

    BOOST_CHECK(s == "1, 2, 3, 4");
}
