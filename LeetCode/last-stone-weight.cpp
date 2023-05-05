// leetcode.com/problems/last-stone-weight/

#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

int lastStoneWeight(vector<int> &stones)
{
    if (stones.size() == 1)
    {
        return stones[0];
    }

    priority_queue<int> pq;
    for (const auto &stone_weight : stones)
    {
        pq.push(stone_weight);
    }

    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int diff = std::max(first, second) - std::min(first, second);
        if (diff > 0)
        {
            pq.push(diff);
        }
    }

    if (pq.empty())
    {
        return 0;
    }

    return pq.top();
}

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    std::cout << lastStoneWeight(stones) << "\n";
    std::cout << lastStoneWeight({2, 7, 4, 1, 8, 1}) << "\n";
}
