// leetcode.com/problems/longest-repeating-character-replacement/

#include <iostream>

using std::string;

int characterReplacement(string s, int k)
{
    int len = s.length();
    if (k >= len - 1 || len == 1)
    {
        return len;
    }

    int ans = 1;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        int left = 0;
        int balance = k;
        for (int right = 0; right < len; right++)
        {
            if (s[right] == c)
            {
                ans = std::max(right - left + 1, ans);
                continue;
            }
            if (balance > 0)
            {
                ans = std::max(right - left + 1, ans);
                balance--;
                continue;
            }
            while (balance == 0)
            {
                if (s[left] != c)
                {
                    balance++;
                }
                left++;
            }
            balance--;
        }
    }

    return ans;
}

int main()
{
    const string s = "ABABA";
    const int k = 1;

    std::cout << characterReplacement(s, k) << "\n";
    std::cout << characterReplacement("ABAB", 2) << "\n";
    std::cout << characterReplacement("ABABA", 1) << "\n";
}
