// leetcode.com/problems/perfect-squares/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int cur = i;
            for (int j = 1; j * j <= i; j++)
            {
                cur = min(cur, dp[i - j * j]);
            }
            dp[i] = 1 + cur;
        }

        return dp[n];
    }
};

int main()
{
    const int n = 10000;
    Solution solution;
    auto ans = solution.numSquares(n);
    cout << ans;
}
