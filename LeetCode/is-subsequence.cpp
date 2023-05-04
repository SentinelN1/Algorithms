// https://leetcode.com/problems/is-subsequence/?envType=study-plan&id=level-1

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        const int len = s.length();
        if (len == 0)
        {
            return true;
        }
        int i = 0;
        for (auto c : t)
        {
            if (s[i] == c)
            {
                i++;
            }
            if (i == len)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    const string s = "axc";
    const string t = "ahbgdc";
    auto ans = solution.isSubsequence(s, t);
    cout << boolalpha << ans;
}