// https://leetcode.com/problems/perfect-squares/

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
                int tmp = dp[i - j * j];
                if (dp[i - j * j] < cur)
                {
                    cur = tmp;
                }
            }
            dp[i] = 1 + cur;
        }

        return dp[n];
    }
};

int main()
{
    // const int n = 12;
    // const int n = 13;
    const int n = 9999;
    Solution solution;
    int ans = solution.numSquares(n);
    cout << ans;
}
