// qwerty_keyboard_test.cpp
// Build using: g++ -ggdb -std=c++0x -Wall -o qk_test qwerty_keyboard_test.cpp -lboost_unit_test_framework
#include "../qwerty_keyboard.h"
#define BOOST_TEST_MODULE Qwerty_keyboard_Test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(kb_test) {

    Qwerty_keyboard kb;
    
    BOOST_CHECK(kb.letter_at_offset_from(-1, 'y') == 't');
    BOOST_CHECK(kb.letter_at_offset_from(1, 'y') == 'u');

    // Boundary conditions
    BOOST_CHECK(kb.letter_at_offset_from(1, 'p') == 'q');
    BOOST_CHECK(kb.letter_at_offset_from(-1, 'q') == 'p');

    BOOST_CHECK(kb.letter_at_offset_from(2, 'l') == 's');
    BOOST_CHECK(kb.letter_at_offset_from(-2, 'z') == 'n');

    BOOST_CHECK(kb.letter_at_offset_from(1, 'G') == 'h');

    const std::string input = "Gwkki";
    const std::string expected = "hello";
    std::string output = "";
    for(char c : input)
        output += kb.letter_at_offset_from(1, c);
    BOOST_CHECK(output == expected);

    //  Should throw exception.
    BOOST_CHECK_THROW(kb.letter_at_offset_from(1, '/'), std::runtime_error);
}