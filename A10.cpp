// Скучная лекция
#include <iostream>
#include <map>

int Calculate(int n, int m)
{
    if (n == 0 || m == 0)
    {
        return std::max(n, m);
    }
    return 2 + Calculate(n - 1, m) + Calculate(n, m - 1);
}

int main()
{
    std::string str;
    std::cin >> str;
    int len = str.length();
    std::map<char, int> m;
    for (int i = 0; i < len; ++i)
    {
        m[str[i]] += 1 + Calculate(i, len - i - 1);
    }
    for (auto p : m)
    {
        std::cout << p.first << ": " << p.second << "\n";
    }
    return 0;
}
