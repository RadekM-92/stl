#include <iostream>
#include <map>

// Zadanie
// Stwórz multimapę i wypełnij ją podanymi wartościami
// map.insert({5, "Ala"});
// map.insert({5, "Ma"});
// map.insert({5, "Kota"});
// map.insert({5, "A"});
// map.insert({5, "Kot"});
// map.insert({5, "Ma"});
// map.insert({5, "Ale"});
// Napisz funkcję, która wyświetli słowa w mapie o liczbie znaków równej 3.

void PrintMap(const std::multimap<int, std::string>& m) {
    for (const auto& el : m) {
        if (3 == el.second.size()) {
            std::cout << el.first << "\t|\t" << el.second << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    std::multimap<int, std::string> mm;
    mm.insert({5, "Ala"});
    mm.insert({5, "Ma"});
    mm.insert({5, "Kota"});
    mm.insert({5, "A"});
    mm.insert({5, "Kot"});
    mm.insert({5, "Ma"});
    mm.insert({5, "Ale"});

    PrintMap(mm);

    return 1;
}