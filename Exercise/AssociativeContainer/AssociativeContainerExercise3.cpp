#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <vector>

// Zadanie
// 1. Wygeneruj zbiór liczb od -20 do 20 i zapisz go w std::set w kolejności malejącej
// 2. Wstaw nowe elementy: -10, 0, 10, 100, -100
// 3. Wygeneruj drugi zbiór z liczb od 0 do 40 i zapisz go w std::multiset
// 4. Wstaw nowe elementy: -10, 0, 10, 100, -100
// 5. Połącz oba zbiory w jeden (ma to być std::multiset)
// 6. Znajdź wszystkie elementy równe 0 i 50
// 7. Co każdy krok wypisuj zawartości kontenerów.

int main() {
    // 1. Wygeneruj zbiór liczb od -20 do 20 i zapisz go w std::set w kolejności malejącej
    std::vector<int> v1(41);
    std::iota(v1.begin(), v1.end(), -20);

    std::set<int, std::greater<>> s1(v1.begin(), v1.end());
    std::cout << "1: " << std::endl;
    for (const auto& el : s1) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    // 2. Wstaw nowe elementy: -10, 0, 10, 100, -100
    s1.insert({-10, 0, 10, 100, -100});
    std::cout << "2: " << std::endl;
    for (const auto& el : s1) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    // 3. Wygeneruj drugi zbiór z liczb od 0 do 40 i zapisz go w std::multiset
    std::iota(v1.begin(), v1.end(), 0);
    std::multiset<int> s2(v1.begin(), v1.end());
    std::cout << "3: " << std::endl;
    for (const auto& el : s2) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    // 4. Wstaw nowe elementy: -10, 0, 10, 100, -100
    s2.insert({-10, 0, 10, 100, -100});
    std::cout << "4: " << std::endl;
    for (const auto& el : s2) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    // 5. Połącz oba zbiory w jeden (ma to być std::multiset)
    s2.merge(s1);
    std::cout << "5: " << std::endl;
    for (const auto& el : s2) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    // 6. Znajdź wszystkie elementy równe 0 i 50
    std::cout << "6: " << std::endl;
    auto [l, u] = s2.equal_range(0);
    while (l != u) {
        if (l != s2.end()) {
            std::cout << *l << ", ";
        }
        l++;
    }
    std::cout << std::endl;

    auto [l_, u_] = s2.equal_range(50);
    while (l_ != u_) {
        if (l_ != s2.end()) {
            std::cout << *l_ << ", ";
        }
        l_++;
    }
    std::cout << std::endl;

    return 1;
}