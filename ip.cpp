#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> ans;
    unsigned long long int num;
    int len = std::to_string(num).length();
    std::cin >> num;

    int d = 10;
    for (int i = 1; i <= 3; i++)
    {
        int forth = num % d;
        if (forth < 256 && i < len)
        {
            int c = 10;
            for (int j = 1; j <= 3; j++)
            {
                int third = (num / d) % c;0
                if (third < 256 && i + j < len)
                {
                    int b = 10;
                    for (int k = 1; k <= 3; k++)
                    {
                        int second = ((num / d) / c) % b;
                        if (second < 256)
                        {
                            int first = ((num / d) / c) / b;
                            if (first < 256 && i + j + k < std::to_string(num).length())
                            {
                                std::string str = std::to_string(first) + "." + std::to_string(second) + "." + std::to_string(third) +
                                                  "." + std::to_string(forth);
                                ans.push_back(str);
                            }
                        }
                        b *= 10;
                    }
                }
                c *= 10;
            }
        }
        d *= 10;
    }

    std::sort(ans.begin(), ans.end());

    for (auto i : ans)
    {
        std::cout << i << " ";
    }

    return 0;
}
