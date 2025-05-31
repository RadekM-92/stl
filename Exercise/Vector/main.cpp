#include <algorithm>
#include <iostream>
#include <vector>

void PrintVec(const std::vector<int>& v) {
    for (auto element : v) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. Stworz pusty wektor
    std::vector<int> vec;
    PrintVec(vec);

    // 2. Wypisz rozmiar i pojemnosc wektora
    std::cout << "2:\t"
              << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    // 3. Zmien rozmiar wektora na 10 i wypelnij go wartosciami 5
    vec.reserve(10);
    vec.insert(vec.begin(), vec.capacity(), 5);
    std::cout << "3:\t";
    PrintVec(vec);

    // 4. Wypisz rozmiar i pojemnosc wektora
    std::cout << "4:\t"
              << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    // 5. Zarezerwuj pamiec na 20 elementow
    vec.reserve(20);

    // 6. Wypisz rozmiar i pojemnosc wektora
    std::cout << "6:\t"
              << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    // 7. Zredukuj pojemnosc wektora metoda shrink_to_fit()
    vec.shrink_to_fit();

    // 8. Wypisz rozmiar i pojemnosc wektora
    std::cout << "8:\t"
              << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    return 1;
}