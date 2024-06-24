// leetcode.com/problems/longest-palindromic-substring/

#include <map>
#include <iostream>

using std::string;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int pos = 0;
        int len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j <= i + 2; j++)
            {
                if (j < s.length() && s[i] == s[j])
                {
                    int k = 0;
                    while (i - k >= 0 && j + k < s.length() && s[i - k] == s[j + k])
                    {
                        if (j - i + 2 * k + 1 > len)
                        {
                            len = j - i + 2 * k + 1;
                            pos = i - k;
                        }
                        k++;
                    }
                }
            }
        }

        return s.substr(pos, len);
    }
};

int main()
{
    Solution solution;
    string str;
    std::cin >> str;
    string ans = solution.longestPalindrome(str);
    std::cout << ans;
    return 0;
}
