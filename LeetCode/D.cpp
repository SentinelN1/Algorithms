#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<bool>> mat(n);
    for (int i = 0; i < n; i++)
    {
        mat[i] = vector<bool>(n);
    }

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        mat[j - 1][i] = true;
    }

    int res = n;
    for (int start = 0; start < n; start++)
    {
        int tmp_res = 0;
        vector<bool> visited(n);
        queue<int> to_visit;

        for (int cur = start; cur < start + n; cur++)
        {
            int i = cur % n;

            if (visited[i])
            {
                continue;
            }

            visited[i] = true;
            tmp_res++;

            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] && !visited[j])
                {
                    to_visit.push(j);
                }
            }

            while (!to_visit.empty())
            {
                int next = to_visit.front();
                visited[next] = true;
                for (int j = 0; j < n; j++)
                {
                    if (mat[next][j] && !visited[j])
                    {
                        to_visit.push(j);
                    }
                }
                to_visit.pop();
            }
        }

        res = min(res, tmp_res);
    }

    std::cout << res;
}