#include <algorithm>
#include <iostream>
#include <vector>

// Zadanie 💻
// Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// Policz, ile jest elementów większych lub równych 5
// Sprawdź, czy istnieje element mniejszy od 1
// Sprawdź, czy wszystkie elementy są większe od 1

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

    auto x = std::count_if(v.begin(), v.end(), [](auto el) { return el >= 5; });
    std::cout << "1: " << x << std::endl;

    auto y = std::any_of(v.begin(), v.end(), [](auto el) { return el < 1; });
    std::cout << "2: " << y << std::endl;

    auto z = std::all_of(v.begin(), v.end(), [](auto el) { return el > 1; });
    std::cout << "3: " << z << std::endl;

    return 1;
}