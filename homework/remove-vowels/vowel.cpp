
#include "vowel.hpp"
#include <iostream>

std::vector<char> VowelsVec = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};

void removeVowels(std::vector<std::string>& text) {
    for (auto& word : text) {
        for (auto sign_it = word.begin(); sign_it != word.end(); ++sign_it) {
            for (const auto& vowel : VowelsVec) {
                if (vowel == *sign_it) {
                    word.erase(sign_it);
                    --sign_it;
                }
            }
        }
    }
}