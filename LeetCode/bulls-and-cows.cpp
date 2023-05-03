// https://leetcode.com/problems/bulls-and-cows/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <map>

using std::string, std::to_string, std::map;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.length();
        int bulls = 0;
        int cows = 0;
        map<char, int> countSecret;
        map<char, int> countGuess;
        for (int i = 0; i < n; i++)
        {
            char s = secret[i];
            char g = guess[i];
            if (s == g)
            {
                bulls++;
            }
            else
            {
                countSecret[s]++;
                countGuess[g]++;

                if (countSecret[g] > 0)
                {
                    countSecret[g]--;
                    countGuess[g]--;
                    cows++;
                }

                if (countGuess[s] > 0)
                {
                    countSecret[s]--;
                    countGuess[s]--;
                    cows++;
                }
            }
        }

        string hint = std::to_string(bulls) + 'A' + to_string(cows) + 'B';
        return hint;
    }
};

int main()
{
    const string secret = "1807";
    const string guess = "7810";
    // const string secret = "1123";
    // const string guess = "0111";
    Solution solution;
    string ans = solution.getHint(secret, guess);
    std::cout << ans;
}
