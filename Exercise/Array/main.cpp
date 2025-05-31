#include <array>
#include <iostream>

void PrintArray(const std::array<int, 10>& a) {
    for (auto element : a) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. Stworz array przechowujacy wartosci calkowitoliczbowe o rozmiarze 10
    std::array<int, 10> arr;
    std::cout << "1:\t";
    PrintArray(arr);

    // 2. Wypelnij ja wartosciami 5
    arr.fill(5);
    std::cout << "2:\t";
    PrintArray(arr);

    // 3. Do czwartego elementu przypisz wartosc 3
    arr.at(4) = 3;
    std::cout << "3:\t";
    PrintArray(arr);

    // 4. Stworz inna tablice o tym samym rozmiarze
    std::array<int, 10> arr_;
    std::cout << "4:\t";
    PrintArray(arr_);

    // 5. Podmien tablice
    arr_.swap(arr);
    std::cout << "5:\t";
    PrintArray(arr_);

    // 6. Wypisz obie tablice, kazda w osobnej linii
    std::cout << "arr:\t";
    PrintArray(arr);
    std::cout << "arr_:\t";
    PrintArray(arr_);

    return 1;
}