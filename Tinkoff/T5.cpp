#include <vector>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> dp(3 * n);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        std::string str;
        std::cin >> str;

        for (int j = 0; j < 3; j++)
        {
            if (str[j] == 'W')
            {
                dp[n * i + j] = -1;
            }
            else
            {
                if (str[j] == '.')
                {
                    dp[n * i + j] = 0;
                }
                else if (str[j] == 'C')
                {
                    dp[n * i + j] = 1;
                }

                if (i > 0)
                {
                    int tmp = -1;
                    for (int k = -1; k <= 1; k++)
                    {
                        if (j + k >= 0 && j + k < 3 && dp[(i - 1) * n + j + k] != 'W') {
                            tmp = std::max(dp[(i - 1) * n + j + k], tmp);
                        }
                    }

                    dp[n * i + j] += tmp;
                }

                ans = std::max(ans, dp[n * i + j]);
            }
        }
    }

    std::cout << ans;

    return 0;
}