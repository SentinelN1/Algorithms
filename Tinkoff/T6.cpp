#include <iostream>
#include <vector>
#include <queue>
#include <map>

typedef unsigned long long int ULLI;

struct Node
{
    int x;
    int y;
    char mode;
    int depth;
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<char>> board(n);
    Node start;
    Node finish;

    for (int i = 0; i < n; i++)
    {
        board[i] = std::vector<char>(n);
        std::string str;
        std::cin >> str;

        for (int j = 0; j < n; j++)
        {
            char c = str[j];

            if (c == 'S')
            {
                start = {i, j, 'K', 0};
            }

            else if (c == 'F')
            {
                finish = {i, j, 'K', 0};
            }

            board[i][j] = c;
        }
    }

    std::map<std::pair<std::pair<int, int>, char>, bool> visited;
    std::queue<Node> to_visit;
    to_visit.push(start);

    // std::cout << finish.x << " " << finish.y << "\n"; 

    while (!to_visit.empty())
    {
        Node node = to_visit.front();

        int i = node.x;
        int j = node.y;
        char mode = node.mode;
        int depth = node.depth;

        // std::cout << i << " " << j << " " << mode << " " << depth << "\n"; 

        if (i == finish.x && j == finish.y)
        {
            std::cout << depth;
            return 0;
        }

        // to_visit.pop();
        // visited[{{i, j}, mode}] = true;

        if (board[i][j] == 'K')
        {
            mode = 'K';
        }
        else if (board[i][j] == 'G')
        {
            mode = 'G';
        }

        int x, y;
        if (mode == 'K')
        {
            x = i + 2;
            y = j + 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i + 2;
            y = j - 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i + 1;
            y = j - 2;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i - 1;
            y = j - 2;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i - 2;
            y = j - 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i - 2;
            y = j + 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i - 1;
            y = j + 2;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i + 1;
            y = j + 2;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }
        }
        else if (mode == 'G')
        {
            x = i + 1;
            y = j + 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i + 1;
            y = j;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i + 1;
            y = j - 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i;
            y = j - 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i - 1;
            y = j - 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i - 1;
            y = j;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i - 1;
            y = j + 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }

            x = i;
            y = j + 1;
            if (0 <= x && x < n && 0 <= y && y < n && !visited[{{x, y}, mode}])
            {
                to_visit.push({x, y, mode, depth + 1});
            }
        }

        to_visit.pop();
        visited[{{i, j}, mode}] = true;
    }

    std::cout << -1;
    return 0;
}