// http://redd.it/2ao99p
// Challenge #171 [Easy] Hex to 8x8 Bitmap
// Usage: 8by8
// Built using g++: g++ -std=c++0x -Wall -o 8by8 chal171.cpp
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <bitset>
#include <algorithm>

int main() {

    std::istream_iterator<std::string> hex_iter(std::cin);
    std::istream_iterator<std::string> end_iter;
    for(; hex_iter != end_iter; ++hex_iter) {
        //  Convert hex string to an integer.
        std::stringstream ss(*hex_iter);
        unsigned long val = 0;
        ss >> std::hex >> val;

        // Convert integer to a string of binary digits.
        std::bitset<8> bits(val);
        std::string byte_str = bits.to_string();

        // Replace all '0's with spaces and all '1's with 'x'
        std::replace(byte_str.begin(), byte_str.end(), '0', ' ');
        std::replace(byte_str.begin(), byte_str.end(), '1', 'x');
        
        std::cout << byte_str << std::endl;
    }

    return 0;
}
