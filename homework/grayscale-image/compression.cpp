
#include "compression.hpp"
#include <iostream>
#include <string>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& img) {
    uint8_t Value = 0;
    uint8_t Amount = 0;
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    for (auto row : img) {
        for (auto column_it = row.begin(); column_it != row.end(); ++column_it) {
            if (column_it == row.begin()) {
                Value = *column_it;
                Amount = 1;
                continue;
            }

            if ((Value != *column_it)) {
                vec.push_back({Value, Amount});
                Amount = 0;
            }

            Value = *column_it;
            Amount = Amount + 1;
        }
        vec.push_back({Value, Amount});
        Amount = 0;
    }
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& img) {
    std::array<std::array<uint8_t, width>, height> arr = {0};
    auto row = 0;
    int column = 0;

    for (auto element : img) {
        for (auto i = 0; i < element.second; ++i) {
            arr[row][column] = element.first;
            column = column + 1;

            if (width <= column) {
                column = 0;
                row = row + 1;
            }
        }
    }
    return arr;
}