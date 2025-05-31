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
    // 1. Stworz wektor o wartosciach 1, 2, 3, 4, 5, 6
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::cout << "1:\t";
    PrintVec(vec);

    // 2. Usun pierwsza wartosc
    auto it = std::remove(vec.begin(), vec.end(), vec[0]);
    std::cout << "2:\t";
    PrintVec(vec);

    // 3. Usuwanie smieci
    vec.erase(it, vec.end());
    std::cout << "3:\t";
    PrintVec(vec);

    // 4. Dodaj wartosc 5 na koncu wektora
    vec.push_back(5);
    std::cout << "4:\t";
    PrintVec(vec);

    // 5. Dodaj wartosc 12 na poczatku wektora korzystajac z metody emplace()
    vec.emplace(vec.begin(), 12);
    std::cout << "5:\t";
    PrintVec(vec);

    // 6. Wypisz rozmiar wektora i maksymalny mozliwy rozmiar
    std::cout << "6:\t"
              << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    // 7. Wypisz zawartosc wektora
    std::cout << "7:\t";
    PrintVec(vec);

    // 8. Wyczysc wektor
    vec.clear();
    std::cout << "8:\t";
    PrintVec(vec);

    // 9. Wypisz rozmiar wektora
    std::cout << "9:\t"
              << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    return 1;
}