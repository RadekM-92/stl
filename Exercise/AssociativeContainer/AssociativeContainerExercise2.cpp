#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>

// Zadanie
// struct Point {
//   int x;
//   int y;
// }
// Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy też dane 4 miast:

// Wrocław (x = 17, y = 51)
// Moskwa (x = 37, y = 55)
// Nowy Jork (x = -74, y = 40)
// Sydney (x = 151, y = -33)
// Część A - łatwiejsza
// Stwórz std::map<std::string, Point>, która będzie przechowywać powyższe miejsca
// Sprawdź czy w mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
// Pobierz i wypisz współrzędne Sydney
// Zadanie
// struct Point {
//   int x;
//   int y;
// }
// Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy też dane 4 miast:

// Wrocław (x = 17, y = 51)
// Moskwa (x = 37, y = 55)
// Nowy Jork (x = -74, y = 40)
// Sydney (x = 151, y = -33)
// Część B - trudniejsza
// Skopiuj te dane do mapy std::map<Point, std::string>
// Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
// Pobierz i wypisz współrzędne Sydney

struct Point {
    int x;
    int y;

    bool operator<(const Point& other) const {
        return x < other.x && y < other.y;
    }
};

int main() {
    // Stwórz std::map<std::string, Point>, która będzie przechowywać powyższe miejsca
    std::map<std::string, Point> cities{
        {"Wrocław", {17, 51}},
        {"Moskwa", {37, 55}},
        {"Nowy Jork", {-74, 40}},
        {"Sydney", {151, -33}}};

    // Sprawdź czy w mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
    std::cout << std::boolalpha << std::any_of(cities.begin(), cities.end(), [](const auto& city) {
        return std::sqrt(city.second.x * city.second.x + city.second.y * city.second.y) <= 70;
    });
    std::cout << std::endl;

    // Pobierz i wypisz współrzędne Sydney
    std::cout << cities["Sydney"].x << ", " << cities["Sydney"].y << std::endl;

    // Skopiuj te dane do mapy std::map<Point, std::string>
    std::map<Point, std::string> cities_inverted;

    std::transform(cities.begin(),
                   cities.end(),
                   std::inserter(cities_inverted, cities_inverted.end()),
                   [](const auto& city) {
                       return std::make_pair(city.second, city.first);
                   });

    // Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
    std::cout << std::boolalpha << std::any_of(cities_inverted.begin(), cities_inverted.end(), [](const auto& city) {
        return std::sqrt(city.first.x * city.first.x + city.first.y * city.first.y) <= 70;
    });
    std::cout << std::endl;

    // Pobierz i wypisz współrzędne Sydney
    for (const auto& [k, v] : cities_inverted) {
        if ("Sydney" == v) {
            std::cout << k.x << ", " << k.y << std::endl;
            break;
        }
    }

    return 1;
}