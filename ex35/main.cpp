// functon tamplate example
#include <iostream>

template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    std::cout << max(3, 5) << std::endl; // 5
    std::cout << max(3.0, 5.0) << std::endl; // 5
    std::cout << max('a', 'b') << std::endl; // b
    return 0;
}