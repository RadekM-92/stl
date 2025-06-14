#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

// Zadanie 💻
// struct Point { int x, y; }
// 1. Utwórz std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};
// 2. Utwórz funkcję do wypisywania zawartości kontenera d
// 3.Napisz 2 komparatory:
//  pointXCompare, który porównuje tylko wartości x ze struktury Point
//  pointYCompare, który porównuje tylko wartości y ze struktury Point
// 4. Sprawdź czy d jest posortowane względem pointXCompare oraz pointYCompare
// 5. Użyj stable_sort do posortowania d względem wartości x
// 6. Użyj sort do posortowania d względem wartości y

struct Point {
    int x, y;
};

int main() {
    std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};

    // 2. Utwórz funkcję do wypisywania zawartości kontenera d
    std::cout << "2: ";
    auto PrintDeque = [](const std::deque<Point>& d1) {
        for (auto el : d1) {
            std::cout << "{" << el.x << ", " << el.y << "}" << ' ';
        }
        std::cout << std::endl;
    };
    PrintDeque(d);

    // 3.Napisz 2 komparatory:
    //  pointXCompare, który porównuje tylko wartości x ze struktury Point
    auto pointXCompare = [](const Point& p1, const Point& p2) {
        return std::minmax(p1.x, p2.x).first;
    };

    //  pointYCompare, który porównuje tylko wartości y ze struktury Point
    auto pointYCompare = [](const Point& p1, const Point& p2) {
        return std::minmax(p1.y, p2.y).first;
    };

    // 4. Sprawdź czy d jest posortowane względem pointXCompare oraz pointYCompare
    std::cout << "4: ";
    std::cout << std::boolalpha << std::is_sorted(d.begin(), d.end(), pointXCompare);
    std::cout << std::endl;
    std::cout << std::boolalpha << std::is_sorted(d.begin(), d.end(), pointYCompare);
    std::cout << std::endl;

    // 5. Użyj stable_sort do posortowania d względem wartości x
    std::stable_sort(begin(d), end(d), [](const Point& p1, const Point& p2) { return p1.x > p2.x; });
    std::cout << "5: ";
    PrintDeque(d);

    // 6. Użyj sort do posortowania d względem wartości y
    std::sort(d.begin(), d.end(), [](const Point& p1, const Point& p2) { return p1.y > p2.y; });
    std::cout << "6: ";
    PrintDeque(d);

    return 1;
}