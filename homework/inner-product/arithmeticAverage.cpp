#include "arithmeticAverage.hpp"
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    auto sum = std::transform_reduce(first.begin(), first.end(), second.begin(), 0, std::plus<>(), std::plus<>());
    auto amount = first.size() + second.size();
    if (0 < amount) {
        return (double)sum / amount;
    } else {
        return 0;
    }
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    auto sum = std::transform_reduce(first.begin(),
                                     first.end(),
                                     second.begin(),
                                     0,
                                     std::plus<>(),
                                     [](const auto& p, const auto& q) {
                                         return (p - q) * (p - q);
                                     });

    return std::sqrt(sum);
}