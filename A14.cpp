#include <iostream>
#include <vector>

int main()
{
    long long int n;
    std::cin >> n;
    std::vector<long long int> histogram(n);
    long long int maxArea = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> histogram[i];
        long long int tmp = histogram[i];
        for (int j = i; j >= 0; --j)
        {
            tmp = std::min(tmp, histogram[j]);
            maxArea = std::max(maxArea, tmp * (i - j + 1));
        }
    }
    std::cout << maxArea;
}
