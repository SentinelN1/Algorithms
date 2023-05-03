// https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan&id=level-1
#include <iostream>
#include <vector>

using std::vector, std::min;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        int prevprev = cost[0];
        int prev = cost[1];

        int curIndex = 2;
        while (curIndex < n)
        {
            int curCost = cost[curIndex] + min(prev, prevprev);

            prevprev = prev;
            prev = curCost;

            ++curIndex;
        }

        return min(prev, prevprev);
    }
};

int main()
{
    vector<int> cost = {10, 15, 20};
    // vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution solution;
    int ans = solution.minCostClimbingStairs(cost);
    std::cout << ans;
}