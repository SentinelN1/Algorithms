// https://leetcode.com/problems/unique-paths/?envType=study-plan&id=level-1
#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++)
        {
            dp[i] = vector<int>(n);
        }

        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (x == 0 || y == 0)
                {
                    dp[x][y] = 1;
                }
                else
                {
                    dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    const int m = 3;
    const int n = 7;
    Solution solution;
    int ans = solution.uniquePaths(m, n);
    std::cout << ans;
}