#include <deque>
#include <iostream>

void PrintDeque(const std::deque<int>& d) {
    for (auto element : d) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. Stworz pusty deque
    std::deque<int> d;

    // 2. Dodaj do niego 5 dowolnych wartosci
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);

    // 3. Wyswietl deque
    std::cout << "3.\t";
    PrintDeque(d);

    // 4. Usun drugi i czwarty element
    d.erase(d.begin() + 1);
    d.erase(d.begin() + 2);
    std::cout << "3.\t";
    PrintDeque(d);

    // 5. Dodaj na poczatek i koniec wartosc 30
    d.push_front(30);
    d.push_back(30);
    std::cout << "4.\t";
    PrintDeque(d);

    // 6. Dodaj na czwartej pozycji liczbe 20
    d.insert(d.begin() + 3, 20);
    std::cout << "6.\t";
    PrintDeque(d);

    return 1;
}