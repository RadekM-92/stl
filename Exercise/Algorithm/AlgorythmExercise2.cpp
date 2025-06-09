#include <algorithm>
#include <iostream>
#include <vector>

// Zadanie — przeszukiwanie 💻
// 1. Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; (ten sam co ostatnio)
// 2. Znajdź wszystkie elementy większe od 6 i wypisz je
// 3. Znajdź wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je
// 4. Przeszukaj wektor v w poszukiwaniu zakresów {6, 6} i {7, 7}
// 5. Użyj std::adjacent_find na wektorze v

int main() {
    // 1. Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; (ten sam co ostatnio)
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

    // 2. Znajdź wszystkie elementy większe od 6 i wypisz je
    {
        std::cout << "2: ";
        auto CompareFun = [](auto el) { return el > 6; };
        auto ElCnt = std::count_if(v.begin(), v.end(), CompareFun);
        auto it = v.begin();
        for (auto i = 0; i < ElCnt; i++) {
            it = std::find_if(it, v.end(), CompareFun);
            if (it != v.end()) {
                std::cout << *it << ' ';
                std::advance(it, 1);
            }
        }
        std::cout << std::endl;
    }

    // 3. Znajdź wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je
    std::cout << "3: ";
    {
        std::vector x = {2, 4, 6, 8};
        auto it = v.begin();
        auto it_ = it;
        while (it_ != v.end()) {
            it_ = std::find_first_of(it, v.end(), x.begin(), x.end());
            if (it_ != v.end()) {
                std::cout << *it_ << ' ';  //<<std::distance(it, it_);
                it = std::next(it_, 1);
            }
        }
        std::cout << std::endl;
    }

    // 4. Przeszukaj wektor v w poszukiwaniu zakresów {6, 6} i {7, 7}
    std::cout << "4: ";
    {
        auto it_66 = std::search_n(v.begin(), v.end(), 2, 6);
        if (it_66 != v.end()) {
            std::cout << "Para {6, 6} istnieje" << std::endl;
        } else {
            std::cout << "Para {6, 6} nie istnieje" << std::endl;
        }
        auto it_77 = std::search_n(v.begin(), v.end(), 2, 7);
        if (it_77 != v.end()) {
            std::cout << "Para {7, 7} istnieje" << std::endl;
        } else {
            std::cout << "Para {7, 7} nie istnieje" << std::endl;
        }
    }

    // 5. Użyj std::adjacent_find na wektorze v
    std::cout << "5: ";
    {
        auto it = std::adjacent_find(v.begin(), v.end());
        if (it != v.end()) {
            std::cout << "Istnieje para jednakowych elementow";
        } else {
            std::cout << "Nie istnieje para jednakowych elementow";
        }
        std::cout << std::endl;
    }

    return 1;
}