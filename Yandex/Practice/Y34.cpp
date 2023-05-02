// Даны два массива одинакового размера. Требуется найти два ближайших по модулю числа, из разных массивов
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> x(n);
    for (auto &i : x)
    {
        std::cin >> i;
    }
    std::sort(x.begin(), x.end());
    
    std::vector<int> y(n);
    for (auto &i : y)
    {
        std::cin >> i;
    }
    std::sort(y.begin(), y.end());

    int a = x[0];
    int b = y[0];
    int ans = std::abs(x[0] - y[0]);
    
    int i = 0;
    int j = 0;
    while(i < n && j < n) {
        int tmp = std::abs(x[i] - y[j]);
        if (tmp < ans) {
            a = x[i];
            b = y[j];
            ans = tmp;
        }

        if (x[i] - y[j] < ans) {
            ++i;
        } else {
            ++j;
        }
    }
    std::cout << a << " " << b << "\n";
    return 0;
}