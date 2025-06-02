#include <array>
#include <iostream>
#include <list>

void PrintArray(const std::array<int, 10>& a) {
    for (auto element : a) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

void PrintList(const std::list<int>& l) {
    for (auto element : l) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. Stworz liste zawierajaca elementy od 0 do 5
    std::list<int> MyList = {0, 1, 2, 3, 4, 5};
    std::cout << "1:\t";
    PrintList(MyList);

    // 2. Usun trzeci element z listy
    MyList.remove(3);
    std::cout << "2:\t";
    PrintList(MyList);

    // 3. Dodaj na poczatek i koniec listy wartosc 10
    MyList.push_front(10);
    MyList.push_back(10);
    std::cout << "3:\t";
    PrintList(MyList);

    // 4. Dodaj na czwartej pozycji liczbe 20
    auto it = MyList.begin();
    std::advance(it, 3);
    MyList.insert(it, 20);
    std::cout << "4:\t";
    PrintList(MyList);

    // 5. Przepisz liste do std::array
    std::array<int, 10> MyArr;
    auto i = 0;

    for (auto element : MyList) {
        MyArr[i] = element;
        i++;
    }

    std::cout << "5:\t";
    PrintArray(MyArr);

    return 1;
}