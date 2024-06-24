// leetcode.com/problems/matchsticks-to-square/

#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;

class Solution
{
public:
    bool traverse(map<int, int> count, int length, vector<int> sides)
    {
        for (auto p : count)
        {
            if (p.second > 0)
            {
                for (auto side : sides)
                {
                    if (side + p.first <= length)
                    {
                        p.second--;
                        side += p.first;
                        //
                    }
                }
                //
            }
        }
    }

    bool makesquare(vector<int> &matchsticks)
    {
        map<int, int> count;
        int sum = 0;
        for (const auto &i : matchsticks)
        {
            count[i]++;
            sum += i;
        }

        if (sum % 4 != 0)
        {
            return false;
        }

        vector<int> sides(4);
    }
};

int main()
{
    vector<int> matchsticks = {3, 3, 3, 3, 4};
    map<int, int, std::greater<int>> count;
    int sum = 0;
    for (const auto &i : matchsticks)
    {
        count[i]++;
        sum += i;
    }
    for (auto it = count.begin(); it != count.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << "\n";
    }
    return 0;
}
