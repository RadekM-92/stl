#include "palindrom.hpp"
#include <algorithm>
#include <iostream>

bool is_palindrome(const std::string& s) {
    std::string s_;

    for (const auto& c : s) {
        if (std::isalpha(c)) {
            if (islower(c)) {
                s_.push_back(c);
            } else {
                s_.push_back(c + 'a' - 'A');
            }
        }
    }

    return std::equal(s_.begin(), s_.begin() + s_.size() / 2, s_.rbegin());
}
