#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Zadanie 💻
// 1. Utwórz poniższy wektor:

//  std::vector<std::pair<int, std::string>> v {
//      {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}
//  };
// 2. Utwórz wektor intów v2 i wypełnij go wszystkimi intami (pierwszymi elementami pary) z wektora v
// 3. Utwórz wektor stringów v3 i wypełnij go konkatenacją string + dwukropek + int ze wszystkich par z wektora v
// 4. Utwórz wektor charów v4 i wypełnij go co drugą literą alfabetu

template <typename Container>
void printCollection(const Container& collection) {
    for (const auto& element : collection) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::pair<int, std::string>> v{
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    // 2. Utwórz wektor intów v2 i wypełnij go wszystkimi intami (pierwszymi elementami pary) z wektora v
    std::vector<int> v2(v.size());
    std::transform(v.begin(), v.end(), v2.begin(), [](const auto& x) { return x.first; });
    std::cout << "2: ";
    printCollection(v2);

    // 3. Utwórz wektor stringów v3 i wypełnij go konkatenacją string + dwukropek + int ze wszystkich par z wektora v
    std::vector<std::string> v3(v.size());
    std::transform(v.begin(), v.end(), v3.begin(), [](const auto& x) {
        return x.second + ":" + std::to_string(x.first);
    });
    std::cout << "3: ";
    printCollection(v3);

    // 4. Utwórz wektor charów v4 i wypełnij go co drugą literą alfabetu
    std::vector<char> v4(26 / 2);
    std::generate(v4.begin(), v4.end(), [i{'a' - 1}]() mutable {
        return i += 2;
    });
    std::cout << "4: ";
    printCollection(v4);

    return 1;
}