//  Alien_translator.h
//
#ifndef  ALIEN_TRANSLATOR_H
#define ALIEN_TRANSLATOR_H

#include <vector>
#include <iterator>
#include <fstream>
#include <boost/algorithm/string.hpp>

#include "qwerty_keyboard.h"

class Alien_translator
{
public:
    Alien_translator() : english_dict_("brit-a-z.txt") {}
    ~Alien_translator() {}

    std::vector<std::string> guess(const std::string& gooblygook) {
        
        std::vector<std::string> guesses;
        
        auto possibilities = generate_possibilities(gooblygook);
        for(auto p : possibilities) {
            if(is_in_dict(p))
                guesses.push_back(p);
        }

        return guesses;
    }

    bool is_gooblygook(const std::string& word) {
        return is_in_dict(word) == false;
    }


private:
    bool is_in_dict(const std::string& word) {

        //  Go to top of dictionary file.
        english_dict_.seekg(0, std::ios_base::beg);

        std::istream_iterator<std::string> word_iter(english_dict_);
        std::istream_iterator<std::string> end_iter;

        for(; word_iter != end_iter; ++word_iter) {
            if(boost::iequals(*word_iter, word)) {
                return true;
            }
        }

        //  Word not found so we are at end-of-file. We have to clear the error
        //  flags.
        english_dict_.clear();

        return false;
    }

    std::vector<std::string> generate_possibilities(const std::string& gooblygook) {
        
        std::vector<std::string> possibilities;
        possibilities.push_back(get_alternate_spelling(gooblygook, -1));        
        possibilities.push_back(get_alternate_spelling(gooblygook, -2));        
        possibilities.push_back(get_alternate_spelling(gooblygook,  1));        
        possibilities.push_back(get_alternate_spelling(gooblygook,  2));        

        return possibilities;
    }

    std::string get_alternate_spelling(const std::string& gooblygook, int offset) {
        std::string alternate = "";
        for(char c : gooblygook)
            alternate += keyboard.letter_at_offset_from(offset, c);

        return alternate;
    }


private:
    std::ifstream english_dict_;
    Qwerty_keyboard keyboard;
};

#endif  //  ALIEN_TRANSLATOR_H
