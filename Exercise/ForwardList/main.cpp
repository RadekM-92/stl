#include <array>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>

void PrintArray(const std::array<int, 10>& a) {
    for (auto element : a) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

void PrintList(const std::forward_list<int>& l) {
    for (auto element : l) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. Stworz liste jednokierunkowa zawierajaca elementy od 0 do 6
    std::forward_list<int> MyForwardList = {0, 1, 2, 3, 4, 5, 6};
    std::cout << "1:\t";
    PrintList(MyForwardList);

    // 2. Usun trzeci element z listy
    MyForwardList.remove(3);
    std::cout << "2:\t";
    PrintList(MyForwardList);

    // 3. Dodaj na poczatek i na koniec listy wartosc 10
    MyForwardList.push_front(10);
    auto it = MyForwardList.begin();
    auto MyForwardListSize = 0;
    for (auto element : MyForwardList) {
        MyForwardListSize++;
    }
    std::advance(it, MyForwardListSize - 1);
    MyForwardList.insert_after(it, 10);
    std::cout << "3:\t";
    PrintList(MyForwardList);

    // 4. Dodaj na czwartej pozycji liczbe 20
    it = MyForwardList.begin();
    std::advance(it, 2);
    MyForwardList.insert_after(it, 20);
    std::cout << "4:\t";
    PrintList(MyForwardList);

    return 1;
}