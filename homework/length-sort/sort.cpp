#include <algorithm>
#include <iostream>

#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string>& flist) {
    std::deque<std::string> deq;

    for (auto element : flist) {
        deq.emplace_back(element);
    }

    std::sort(deq.begin(), deq.end(), [](std::string str1, std::string str2) {
        if (str1.size() == str2.size()) {
            auto it1 = str1.begin();
            auto it2 = str2.begin();
            for (; it1 != str1.end(); ++it1, ++it2) {
                if (*it1 == *it2) {
                    continue;
                } else {
                    if (*it1 < *it2) {
                        return true;
                    } else if (*it1 > *it2) {
                        return false;
                    }
                }
            }
        } else {
            if (str1.size() < str2.size()) {
                return true;
            } else if (str1.size() > str2.size()) {
                return false;
            }
        }
    });

    return deq;
}
