#include <iostream>
#include <vector>

int Recursion(int n, std::vector<int> &res)
{
    if (n < 8)
    {
        res[n] = n;
        return n;
    }
    if (res[n] != 0)
    {
        return res[n];
    }
    int tmp = n;
    for (int k = 1; k * k * k <= n; ++k)
    {
        if (res[n - k * k * k] == 0)
        {
            res[n - k * k * k] = Recursion(n - k * k * k, res);
        }
        tmp = std::min(tmp, res[n - k * k * k]);
    }
    return 1 + tmp;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> results(n + 1);

    std::cout << Recursion(n, results);

    return 0;
}
