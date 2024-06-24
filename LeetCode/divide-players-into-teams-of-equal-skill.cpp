// leetcode.com/problems/divide-players-into-teams-of-equal-skill/
#include <iostream>
#include <vector>
#include <map>

using std::vector, std::map;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int number_of_teams = skill.size() / 2;

        int sum_skill = 0;
        map<int, int> skill_count;
        for (int i = 0; i < skill.size(); i++)
        {
            sum_skill += skill[i];
            skill_count[skill[i]]++;
        }

        if (sum_skill % number_of_teams != 0)
        {
            return -1;
        }
        int desired_team_skill = sum_skill / number_of_teams;
        long long int chemistry = 0;

        for (int i = 0; i < skill.size(); i++)
        {
            if (skill_count[skill[i]] == skill_count[desired_team_skill - skill[i]])
            {
                chemistry += skill[i] * (desired_team_skill - skill[i]);
            }
            else
            {
                return -1;
            }
        }
        return chemistry / 2;
    }
};

int main()
{
    Solution solution;
    // vector<int> skill = {1, 1, 1, 2, 2, 2};
    // vector<int> skill = {3, 2, 5, 1, 3, 4};
    // vector<int> skill = {3, 4};
    vector<int> skill = {1, 1, 2, 3};
    int chemistry = solution.dividePlayers(skill);
    std::cout << chemistry;
    return 0;
}