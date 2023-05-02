#include <iostream>
#include <vector>

int main()
{
    int n, m, count = 0;
    std::cin >> m >> n;
    std::vector<std::pair<int, int>> sectors(n);
    for (size_t i = 0; i < n; i++)
    {
        ++count;
        int a, b;
        std::cin >> a >> b;
        sectors[i].first = a;
        sectors[i].second = b;
        for (size_t j = 0; j < i; j++)
        {
            if (sectors[i].second >= sectors[j].first && sectors[i].first <= sectors[j].second)
            {
                --count;
                sectors[j].first = 0;
                sectors[j].second = 0;
            }
        }
    }
    std::cout << count;
}
