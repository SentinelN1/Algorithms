#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> numbers(n);
    std::multiset<int> count;
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
        count.insert(numbers[i]);
        if (i + 1 >= k) {
            std::cout << *count.begin() << "\n";
            count.erase(count.lower_bound(numbers[i - k + 1]));
        }
    }
    return 0;
}
