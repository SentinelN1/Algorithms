// https://leetcode.com/problems/longest-palindrome/?envType=study-plan&id=level-1

#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> count;
        for (auto c : s)
        {
            count[c]++;
        }
        int odd = 0;
        int ans = 0;
        for (auto i : count)
        {
            if (i.second % 2 == 0)
            {
                ans += i.second;
            }
            else
            {
                ans += i.second - 1;
                odd = 1;
            }
        }
        ans += odd;
        return ans;
    }
};

int main()
{
    Solution solution;
    // const string s = "abccccdd";
    const string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    auto ans = solution.longestPalindrome(s);
    cout << ans;
}