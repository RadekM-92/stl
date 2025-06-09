#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

/*
Zadanie
Napisz funkcję middle, która może być wywoływana na różnych kontenerach. Funkcja ta powinna zwracać środkowy element w kolekcji.
Napisz ją w konwencji algorytmów z biblioteki STL, czyli jako argumenty chcemy podać 2 iteratory:

auto middle(Iter first, Iter last);

Za Iter musisz podstawić właściwe typy parametrów i napisać kilka przeciążeń tej funkcji. Możesz też... użyć szablonów, jeśli wiesz jak :).
*/

template <typename Iter>
auto middle(Iter first, Iter last) {
    auto size = std::distance(first, last);
    return *std::next(first, size / 2);
}

int main() {
    std::vector vec = {1, 2, 3, 4, 5, 6};
    std::list list = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f};
    std::forward_list flist = {'a', 'b', 'c', 'd', 'e', 'f'};

    std::cout << middle(vec.begin(), vec.end()) << std::endl;
    std::cout << middle(list.begin(), list.end()) << std::endl;
    std::cout << middle(flist.begin(), flist.end()) << std::endl;

    return 1;
}