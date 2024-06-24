#include <vector>
#include <iostream>

typedef unsigned long long int ULLI;

int main()
{
    int n;
    std::vector<std::vector<int>> ans;
    char dir;
    std::cin >> n >> dir;
    std::vector<std::vector<ULLI>> matrix(n);

    for (ULLI i = 0; i < n; i++)
    {
        std::vector<ULLI> row(n);
        for (ULLI j = 0; j < n; j++)
        {
            std::cin >> row[j];
        }
        matrix[i] = row;
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            ULLI tmp = matrix[i][j];
            if (dir == 'L')
            {
                if (matrix[i][j] != matrix[j][n - 1 - i])
                {
                    ans.push_back({i, j, j, n - 1 - i});
                    // std::cout << i << " " << j << " " << j << " " << n - 1 - i << "\n";
                    // ans++;
                }

                if (matrix[j][n - 1 - i] != matrix[n - 1 - i][n - 1 - j])
                {
                    ans.push_back({j, n - 1 - i, n - 1 - i, n - 1 - j});
                    // std::cout << j << " " << n - 1 - i << " " << n - 1 - i << " " << n - 1 - j << "\n";
                    // ans++;
                }

                if (matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i])
                {
                    ans.push_back({n - 1 - i, n - 1 - j, n - 1 - j, i});
                    // std::cout << n - 1 - i << " " << n - 1 - j << " " << n - 1 - j << " " << i << "\n";
                    // ans++;
                }

                // if (matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i]) {
                //     std::cout << n - 1 - i << " " << n - 1 - j << " " << n - 1 - j << " " << i << "\n";
                // }
            }
            else if (dir == 'R')
            {
                if (matrix[i][j] != matrix[n - 1 - j][i])
                {
                    ans.push_back({i, j, n - 1 - j, i});
                    // std::cout << i << " " << j << " " << n - 1 - j << " " << i << "\n";
                    // ans++;
                }

                if (matrix[n - 1 - j][i] != matrix[n - 1 - i][n - 1 - j])
                {
                    ans.push_back({n - 1 - j, i, n - 1 - i, n - 1 - j});
                    // std::cout << n - 1 - j << " " << i << " " << n - 1 - i << " " << n - 1 - j << "\n";
                    // ans++;
                }

                if (matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i])
                {
                    ans.push_back({n - 1 - i, n - 1 - j, j, n - 1 - i});
                    // std::cout << n - 1 - i << " " << n - 1 - j << " " << j << " " << n - 1 - i << "\n";
                    // ans++;
                }

                // if (matrix[i][n - 1 - j] = matrix[n - 1 - j][i]) {
                //     std::cout << i << " " << n - 1 - j << " " << n - 1 - j << " " << i << "\n";
                // }
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (auto i : ans)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }

    return 0;
}