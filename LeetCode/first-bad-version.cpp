// https://leetcode.com/problems/first-bad-version/?envType=study-plan&id=level-1

#include <iostream>

const int bad = 2;

bool isBadVersion(int version)
{
    return version >= bad;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        unsigned long long int lower = 1;
        unsigned long long int upper = n;
        unsigned long long int middle = (lower + upper) / 2;

        if (isBadVersion(lower))
        {
            return 1;
        }

        while (lower + 1 < upper)
        {
            if (isBadVersion(middle))
            {
                upper = middle;
            }
            else
            {
                lower = middle;
            }
            middle = (lower + upper) / 2;
        }

        return upper;
    }
};

int main()
{
    const int n = 5;
    Solution solution;
    int ans = solution.firstBadVersion(n);
    std::cout << ans;
}
