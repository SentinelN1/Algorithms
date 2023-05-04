// https://leetcode.com/problems/number-of-islands/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using std::vector, std::queue, std::stack, std::pair, std::map;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        const char LAND = '1';
        const char WATER = '0';

        map<pair<int, int>, bool> visited;

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        int j = 0;
        int i = 0;
        for (j = 0; j < m; j++)
        {
            for (i = 0; i < n; i++)
            {
                if (grid[j][i] == LAND && !visited[{j, i}])
                {
                    ++ans;
                    queue<pair<int, int>> toVisit;
                    toVisit.push({j, i});
                    visited[{j, i}] = true;

                    while (!toVisit.empty())
                    {
                        auto cur = toVisit.front();
                        // visited[cur] = true;
                        toVisit.pop();

                        int r = cur.first;
                        int c = cur.second;

                        if (c + 1 < n && grid[r][c + 1] == LAND && !visited[{r, c + 1}])
                        {
                            toVisit.push({r, c + 1});
                            visited[{r, c + 1}] = true;
                        }
                        if (r + 1 < m && grid[r + 1][c] == LAND && !visited[{r + 1, c}])
                        {
                            toVisit.push({r + 1, c});
                            visited[{r + 1, c}] = true;
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == LAND && !visited[{r, c - 1}])
                        {
                            toVisit.push({r, c - 1});
                            visited[{r, c - 1}] = true;
                        }
                        if (r - 1 >= 0 && grid[r - 1][c] == LAND && !visited[{r - 1, c}])
                        {
                            toVisit.push({r - 1, c});
                            visited[{r - 1, c}] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    // vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
    //                              {'1', '1', '0', '1', '0'},
    //                              {'1', '1', '0', '0', '0'},
    //                              {'0', '0', '0', '0', '0'}};

    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};

    // vector<vector<char>> grid = {{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1'},
    //                              {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0'},
    //                              {'1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1'},
    //                              {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '0'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    //                              {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};

    Solution solution;
    auto ans = solution.numIslands(grid);
    std::cout << ans << '\n';
}