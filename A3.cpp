// Коллекционер Диего
#include <iostream>
#include <algorithm>
#include <set>

int main()
{
    int n, k;
    std::cin >> n;
    std::set<int> s;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        s.insert(tmp);
    }

    std::cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int p;
        std::cin >> p;
        auto it = s.lower_bound(p);
        int count = std::distance(s.begin(), it);
        std::cout << count << "\n";
    }

    return 0;
}
