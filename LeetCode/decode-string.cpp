// leetcode.com/problems/decode-string/

#include <iostream>
#include <stack>

using std::stack;
using std::string;

string decodeString(string s)
{
    string ans = "";
    int num = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';
            num = 10 * num + digit;
            continue;
        }
        if (s[i] == '[')
        {
            stack<char> brackets;
            string str = "";
            ++i;
            while (!(brackets.empty() && s[i] == ']'))
            {
                if (s[i] == ']')
                {
                    brackets.pop();
                }
                if (s[i] == '[')
                {
                    brackets.push(s[i]);
                }
                str = str + s[i];
                ++i;
            }
            string tmp = decodeString(str);
            for (int j = 0; j < num; ++j)
            {
                ans = ans + tmp;
            }
            num = 0;
            continue;
        }
        ans = ans + s[i];
    }
    return ans;
}

int main()
{
    const string s = "3[a]2[bc]"; // -> aaabcbc
    // const string s = "c";
    // const string s = "a2[c]";
    // const string s = "3[a2[c]]";
    // const string s = "2[abc]3[cd]ef";

    auto ans = decodeString(s);
    std::cout << ans;
}