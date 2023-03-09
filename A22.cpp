#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> numbers(n + 1);
    for (int i = 1; i <= n; ++i) {
        numbers[i] = std::vector<int>(3);
        std::cin >> numbers[i][0];
    }

    return 0;
}