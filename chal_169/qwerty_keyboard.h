/*
qwerty_keyboard.h

Represents all the *letters* on a QWERTY keyboard layout and provides 
operations to get a letter at an offset to the left or right of an existing 
letter.

For example, the top row of letters on the QWERTY keyboard is, qwertyuiop. If we
ask the querty_keyboard for the letter offset two positions to the right of the
letter 'q', then it will give us 'e'. Or, if we ask it for the letter one
position to the left of 'q', it will give us 'p'. In the second example, it 
"wraps around".
*/
#ifndef QWERTY_KEYBOARD_H
#define QWERTY_KEYBOARD_H

#include <locale>
#include <array>

class Qwerty_keyboard
{
public:
    Qwerty_keyboard() :
        letter_rows_({"qwertyuiop", "asdfghjkl", "zxcvbnm"}) {}

    ~Qwerty_keyboard() {}

    // Returns the letter at offset from the letter specified in from.
    char letter_at_offset_from(int offset, char from) {

        auto row_of_chars = find_row(std::tolower(from));
        auto pos = row_of_chars.find_first_of(std::tolower(from));
        int len = row_of_chars.length();

        int new_letter_pos = pos + offset;
        if(new_letter_pos >= len) new_letter_pos -= len;
        if(new_letter_pos < 0)   new_letter_pos = len + new_letter_pos;

        return row_of_chars[new_letter_pos];
    }

private:
    std::string find_row(char c) {
        for(auto r : letter_rows_) {
            if(r.find_first_of(c) != std::string::npos) {
                return r;
            }
        }
        
        throw std::runtime_error("Could not find a matching row of letters!");
    }

private:
    const std::array<const std::string, 3> letter_rows_;
};

#endif // QWERTY_KEYBOARD_H
