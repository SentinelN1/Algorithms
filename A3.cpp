// Коллекционер Диего
#include <iostream>
#include <algorithm>
#include <vector>
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
    for (int i = 0; i < k; i++)
    {
        int p;
        std::cin >> p;
        int count = std::count_if(s.begin(), s.end(), [p](int i)
                                  { return i < p; });
        std::cout << count << "\n";
    }

    return 0;
}
