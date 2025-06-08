#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    // 1. Utwórz lambdę, która przyjmie 2 argumenty typu int oraz zwróci ich iloczyn
    auto multiply = [](int arg1, int arg2) { return arg1 * arg2; };
    std::cout << "1: " << multiply(2, 4) << std::endl;

    // 2. Utwórz lambdę, która do podanego ciągu znaków doda cudzysłów. np.krowa -> "krowa"
    auto AddQuotationMarks = [](std::string& str1) {
        str1.insert(str1.begin(), '"');
        str1.push_back('"');
        return str1;
    };
    std::string Pies = "Pies";
    std::cout << "2: " << AddQuotationMarks(Pies) << std::endl;

    // 3. Utwórz lambdę, która wypisze ciąg znaków *. Przy każdym zawołaniu funkcji powinniśmy dostać ciąg dłuższy o jedną *. Kolejno:
    //      *
    //      **
    //      ***
    auto GenerateAsterix = [cnt = 0]() mutable {
        for (auto i = 0; i <= cnt; ++i) {
            std::cout << '*';
        }
        std::cout << std::endl;

        cnt = cnt + 1;
    };

    std::cout << "3: " << std::endl;
    GenerateAsterix();
    GenerateAsterix();
    GenerateAsterix();
    GenerateAsterix();

    // 4. Utwórz std::vector<int> i wypełnij go dowolnymi wartościami
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    // 5. Utwórz lambdę, która przechwyci ten wektor, oraz wyświetli jego zawartość
    auto PrintVec = [&vec]() {
        for (auto el : vec) {
            std::cout << el << ", ";
        }
        std::cout << std::endl;
    };

    std::cout << "5: ";
    PrintVec();

    // 6. Utwórz lambdę, która w swoim argumencie przyjmie int i go wyświetli
    auto PrintNumber = [](int x) { std::cout << x << std::endl; };
    std::cout << "6: ";
    PrintNumber(152);

    // 7. Wykorzystaj lambdę z pkt. 3 w algorytmie std::for_each() do wyświetlenia całego kontenera
    std::cout << "7: ";
    std::for_each(vec.begin(), vec.end(), PrintNumber);

    return 1;
}