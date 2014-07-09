// string_utils.h

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <sstream>
#include <string>
#include <algorithm>

namespace string_utils {

//  Build a string of items separated by some separator string.
//  Eg:
//  std::array<int, 4> ar = {1, 2, 3, 4};
//  fmt_as_list(ar); // => "1, 2, 3, 4"
template<typename C> std::string fmt_as_list(
    const C& container,
    const std::string& separator = ", ") {

    std::stringstream ss;
    auto last = container.size()-1;

    auto iter = container.begin();
    auto end = container.end();

    for(size_t i = 0; iter != end; ++i, ++iter) {
        ss << *iter;
        if(i < last) ss << separator;
    }

    return ss.str();

}

std::string remove_punctuation(const std::string& s) {
    std::string result;
    std::remove_copy_if(s.begin(), s.end(), std::back_inserter(result),
        std::ptr_fun<int, int>(&std::ispunct));
    return result;
}

}   // namespace string_utils

#endif
