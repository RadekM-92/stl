
#include "transform.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& l, std::deque<int>& d) {
    l.sort();
    auto it_l = std::unique(l.begin(), l.end());
    l.erase(it_l, l.end());

    std::sort(d.begin(), d.end());
    auto it_d = std::unique(d.begin(), d.end());
    d.erase(it_d, d.end());

    std::map<int, std::string> m;
    std::transform(d.begin(), d.end(), l.begin(), std::inserter(m, m.end()), [](const auto& d_, const auto& l_) { return std::make_pair(d_, l_); });

    return m;
}