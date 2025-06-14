
// Zadanie 💻
// 1. Utwórz wektor v1 z liczbami od 1 do 1000
// 2. Oblicz sumę tych liczb
// 3. Utwórz wektor v2 z 1000 elementów powtarzających się w następującej sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ...
// 4. Oblicz iloczyn skalarny wektorów v1 i v2
// 5. Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z wektora v2

#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

template <typename Collection_t>
void PrintCollection(Collection_t x) {
    for (const auto& el : x) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. Utwórz wektor v1 z liczbami od 1 do 1000
    size_t size = 1000;
    std::vector<int> v1(size);
    std::iota(v1.begin(), v1.end(), 1);
    std::cout << "1: " << std::endl;
    PrintCollection(v1);

    // 2. Oblicz sumę tych liczb
    auto sum = std::reduce(std::execution::par, v1.begin(), v1.end(), 0);
    std::cout << "2: " << sum << std::endl;

    // 3. Utwórz wektor v2 z 1000 elementów powtarzających się w następującej sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ...
    std::vector<int> v2(size);
    std::generate(v2.begin(), v2.end(), [i = 0]() mutable {
        if (2 < i)
            i = 0;
        return i++ - 1;
    });
    std::cout << "3: " << std::endl;
    PrintCollection(v2);

    // 4. Oblicz iloczyn skalarny wektorów v1 i v2
    auto product = std::transform_reduce(v1.begin(), v1.begin(), v2.begin(), 0);
    std::cout << "4: " << product << std::endl;

    // 5. Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z wektora v2
    // 1, 2, 3, 4, 5, 6, 7
    // -1, 0, 1, -1, 0, 1
    // = 3 + 7 + ....
    auto sum2 = std::transform_reduce(v1.begin(), v1.end(), v2.begin(), 0, std::plus<>(),
                                      [](const auto& x1, const auto& x2) {
                                          if (0 < x2)
                                              return x1;
                                          else
                                              return 0;
                                      });
    std::cout << "5: " << sum2 << std::endl;

    return 1;
}