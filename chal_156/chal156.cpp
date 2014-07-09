// http://www.reddit.com/r/dailyprogrammer
// Challenge 156-Easy - Create a simple decoder
// Usage: decode
//    Decode from standard input. Will typically be used like this:
//    decode < file.in
// Built using g++: g++ -std=c++0x -Wall -o decode chal156.cpp
//
#include <iostream>

char decode(char ch) {
    return ch == '\n' ? ch : ch-4;
}

int main() {

    char ch = 0;
    while((ch = std::getchar()) != EOF) {
        std::cout << decode(ch);
    }
}
