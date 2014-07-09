// http://redd.it/29od55
// Challenge 169-Intermediate - Home-row Spell Check
// Usage: aliensp
//    Spell check and correct alien input.
//    aliensp < file.in
// Built using g++: g++ -std=c++0x -Wall -o alien_trans chal169.cpp
//
#include <iostream>

#include "alien_translator.h"
#include "string_utils.h"


int main() {

    //  For each word, check if it's a real word as opposed to gooblygook. If
    //  it's a real word, print it. Otherwise try to guess what the word could
    //  be and print the guesses. If there are no guesses, then print the
    //  original gooblygook.

    Alien_translator translator;

    std::istream_iterator<std::string> word_iter(std::cin);
    std::istream_iterator<std::string> end_iter;

    for(; word_iter != end_iter; ++word_iter) {
        std::string word = string_utils::remove_punctuation(*word_iter);

        if(translator.is_gooblygook(word)) {
            auto guesses = translator.guess(word);
            if(guesses.size() > 0)
                std::cout << '{' << string_utils::fmt_as_list(guesses) << "} ";
            else
                std::cout << word << ' ';
        }
        else
            std::cout << word << ' ';
    }

    return 0;
}
