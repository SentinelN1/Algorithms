// leetcode.com/problems/longest-substring-without-repeating-characters/

#include <map>
#include <iostream>

using std::string;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::map<char, int> letters;
        int n = 0;
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            while (j < s.length() && letters[s[j]] == 0)
            {
                letters[s[j]]++;
                j++;
            }
            n = std::max(n, j - i);
            letters[s[i]]--;
        }
        return n;
    }
};

int main()
{
    Solution solution;
    string str;
    std::cin >> str;
    int ans = solution.lengthOfLongestSubstring(str);
    std::cout << ans;
    return 0;
}