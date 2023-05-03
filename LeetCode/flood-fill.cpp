// https://leetcode.com/problems/flood-fill/?envType=study-plan&id=level-1

#include <iostream>
#include <queue>

using std::vector, std::pair, std::queue;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        auto ans = image;
        int prevColor = ans[sr][sc];

        if (prevColor != color)
        {
            int rows = ans.size();
            int cols = ans[0].size();

            queue<pair<int, int>> q;

            ans[sr][sc] = color;
            q.push({sr, sc});

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                int row = cur.first;
                int col = cur.second;
                if (row - 1 >= 0 && ans[row - 1][col] == prevColor)
                {
                    ans[row - 1][col] = color;
                    q.push({row - 1, col});
                }
                if (row + 1 < rows && ans[row + 1][col] == prevColor)
                {
                    ans[row + 1][col] = color;
                    q.push({row + 1, col});
                }
                if (col - 1 >= 0 && ans[row][col - 1] == prevColor)
                {
                    ans[row][col - 1] = color;
                    q.push({row, col - 1});
                }
                if (col + 1 < cols && ans[row][col + 1] == prevColor)
                {
                    ans[row][col + 1] = color;
                    q.push({row, col + 1});
                }
            }
        }
        return ans;
    }
};

int main()
{
    // vector<vector<int>> image = {{1, 1, 1},
    //                              {1, 1, 0},
    //                              {1, 0, 1}};
    // const int sr = 1;
    // const int sc = 1;
    // const int color = 0;

    // vector<vector<int>> image = {{0, 0, 0},
    //                              {0, 0, 0},
    //                              {0, 0, 0}};
    // const int sr = 0;
    // const int sc = 0;
    // const int color = 0;

    vector<vector<int>> image = {{0, 0, 0},
                                 {0, 1, 0}};
    const int sr = 1;
    const int sc = 1;
    const int color = 2;

    Solution solution;
    auto ans = solution.floodFill(image, sr, sc, color);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            std::cout << ans[i][j] << " ";
        }
        std::cout << "\n";
    }
}
