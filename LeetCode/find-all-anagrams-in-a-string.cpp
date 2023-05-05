// leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::map;
using std::string;
using std::vector;

vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    map<char, int> chars;
    for (auto c : p)
    {
        chars[c]++;
    }

    int s_len = s.length();
    int p_len = p.length();
    int left = 0;
    for (int right = 0; right < s_len; right++)
    {
        chars[s[right]]--;

        bool cur = true;

        for (auto i : chars)
        {
            if (i.second != 0)
            {
                cur = false;
                break;
            }
        }

        if (cur)
        {
            ans.push_back(left);
        }

        if (right - left == p_len - 1)
        {
            chars[s[left]]++;
            left++;
        }
    }

    return ans;
}

int main()
{
    const string s = "cbaebabacd";
    const string p = "abc";
    // ans = findAnagrams(s, p);
    // for (auto i : ans)
    // {
    //     std::cout << i << ' ';
    // }
    // std::cout << '\n';

    auto ans = findAnagrams("abab", "ab");
    for (auto i : ans)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}