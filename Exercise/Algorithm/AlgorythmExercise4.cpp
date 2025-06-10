#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

// Zadanie 💻
// 1. Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// 2. Usuń wszystkie duplikaty z v
// 3. Wypisz wszystkie elementy, używając std::copy i std::ostream_iterator
// 4. Pomieszaj losowo wszystkie elementy
// 5. Wypisz je raz jeszcze

template <typename Container>
void printCollection(const Container& collection) {
    for (const auto& element : collection) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

    // 2. Usuń wszystkie duplikaty z v
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());

    std::cout << "2: ";
    printCollection(v);

    // 3. Wypisz wszystkie elementy, używając std::copy i std::ostream_iterator
    std::cout << "3: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // 4. Pomieszaj losowo wszystkie elementy
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);

    // 5. Wypisz je raz jeszcze
    std::cout << "5: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 1;
}