// leetcode.com/problems/backspace-string-compare

#include <iostream>
#include <stack>

using std::stack;
using std::string;

bool backspaceCompare(string s, string t)
{
    const char BACKSPACE = '#';
    stack<char> str1;
    stack<char> str2;

    for (auto c : s)
    {
        if (c == BACKSPACE)
        {
            if (!str1.empty())
            {
                str1.pop();
            }
            continue;
        }
        else
        {
            str1.push(c);
        }
    }

    for (auto c : t)
    {
        if (c == BACKSPACE)
        {
            if (!str2.empty())
            {
                str2.pop();
            }
            continue;
        }
        else
        {
            str2.push(c);
        }
    }

    while (!str1.empty() && !str2.empty())
    {
        auto c1 = str1.top();
        auto c2 = str2.top();
        if (c1 != c2)
        {
            return false;
        }
        str1.pop();
        str2.pop();
    }

    if (!str1.empty() || !str2.empty())
    {
        return false;
    }

    return true;
}

int main()
{
    // const string s = "ab#c";
    // const string t = "ad#c";
    // const string s = "ab##";
    // const string t = "c#d#";
    // const string s = "a#c";
    // const string t = "b";
    const string s = "y#fo##f";  // -> "f"
    const string t = "y#f#o##f"; // -> "f"
    bool ans = backspaceCompare(s, t);
    std::cout << std::boolalpha << ans;
}