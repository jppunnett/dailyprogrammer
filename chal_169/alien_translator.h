//  Alien_translator.h
//
#ifndef  ALIEN_TRANSLATOR_H
#define ALIEN_TRANSLATOR_H

#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <fstream>
#include <boost/algorithm/string.hpp>

class Alien_translator
{
public:
    Alien_translator() {
        // Build an in-memory list of words in dictionary. This is faster than
        //  looking up the word using File IO.
        std::ifstream english_dict("brit-a-z.txt");
        std::istream_iterator<std::string> word_iter(english_dict);
        std::istream_iterator<std::string> end_iter;
        for(; word_iter != end_iter; ++word_iter)
            dict_.insert(*word_iter);

        const std::string rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm",
                                    "QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        std::string keys;
        for(const auto &r : rows) keys += r;

        for(auto i : {-2, -1, 1, 2}) {
            std::string shifted;
            for(const auto &r : rows) {
                size_t pos = i < 0 ? r.size() - (i * -1): i;
                shifted += r.substr(pos) + r.substr(0, pos);
            }
            
            fixes_.push_back(make_trans(keys, shifted));
        }
    }

    ~Alien_translator() {}

    std::vector<std::string> guess(const std::string& gooblygook) {
        auto alternatives = get_alternatives(gooblygook);

        std::vector<std::string> guesses;
        for(auto alt : alternatives)
            if(is_in_dict(alt))
                guesses.push_back(alt);

        return guesses;
    }

    bool is_gooblygook(const std::string& word) {
        return is_in_dict(word) == false;
    }


private:
    bool is_in_dict(const std::string& word) {
        return dict_.find(word) != dict_.end();
    }

    std::vector<std::string> 
    get_alternatives(const std::string& gooblygook) {
        std::vector<std::string> alternatives;
        for(const auto& f : fixes_)
            alternatives.push_back(translate(gooblygook, f));
        return alternatives;
    }

    std::map<char, char>
    make_trans(const std::string& keys, const std::string& shifted) {
        if(keys.size() != shifted.size())
            throw std::runtime_error("keys.size() != shifted.size()");

        std::map<char, char> trans_table;
        for(size_t i = 0; i < shifted.size(); ++i)
            trans_table.insert(std::pair<char,char>(keys[i],shifted[i]));

        return trans_table;
    }

    std::string translate(const std::string& gooblygook, 
                          const std::map<char, char>& trans_table) {
        std::string translated;
        for(auto c : gooblygook)
            translated += trans_table.at(c);
        return translated;
    }


private:
    std::set<std::string> dict_;
    std::vector<std::map<char, char> > fixes_;
};

#endif  //  ALIEN_TRANSLATOR_H
