#include <iostream>
#include <concepts> // C++20 feature
#include <ranges>   // C++20 feature

int main() {
    auto numbers = {1, 2, 3, 4, 5};
    for (auto n : numbers | std::views::filter([](int x) { return x % 2 == 0; }))
        std::cout << n << " ";
    return 0;
}
