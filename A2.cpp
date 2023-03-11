// Красивая строка
#include <iostream>

int main()
{
    int k;
    std::string str;
    std::cin >> k >> str;
    int len = str.length();
    if (len <= 1)
    {
        std::cout << len;
        return 0;
    }
    int maxBeauty = 1;
    for (char c = 'a'; c <= 'z'; c++)
    {
        int first = 0;
        int second = 1;
        int balance = k - (str[first] != c) - (str[second] != c);
        while (second < len)
        {
            while (balance > 0 && second + 1 < len)
            {
                ++second;
                if (str[second] != c)
                {
                    --balance;
                }
                maxBeauty = std::max(maxBeauty, second - first + 1);
            }
            while (balance <= 0 && first < len - 1)
            {
                if (str[first] != c)
                {
                    ++balance;
                }
                maxBeauty = std::max(maxBeauty, second - first + 1);
                first++;
            }
        }
    }
    std::cout << maxBeauty;
    return 0;
}
