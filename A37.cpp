// Числа
#include <iostream>
#include <queue>
#include <map>

int main()
{
    int start, finish;
    std::cin >> start >> finish;
    std::map<int, int> m;
    std::queue<int> q;

    int current = finish;
    q.push(current);
    m[current] = current;
    while (m[start] == 0)
    {
        // std::cout << "Current = " << current << ":\n";
        int up = current - 1000;
        if (current / 1000 != 1 && m[up] == 0)
        {
            m[up] = current;
            q.push(up);
            // std::cout << "\tup = " << up << "\n";
        }

        int down = current + 1;
        if (current % 10 != 9 && m[down] == 0)
        {
            m[down] = current;
            q.push(down);
            // std::cout << "\tdown = " << down << "\n";
        }

        int left = 10 * (current % 1000) + current / 1000;
        if (m[left] == 0)
        {
            m[left] = current;
            q.push(left);
            // std::cout << "\tleft = " << left << "\n";
        }

        int right = 1000 * (current % 10) + current / 10;
        if (m[right] == 0)
        {
            m[right] = current;
            q.push(right);
            // std::cout << "\tright = " << right << "\n";
        }

        q.pop();
        current = q.front();
        // system("pause");
    }

    current = start;
    while (current != finish)
    {
        std::cout << current << "\n";
        current = m[current];
    }
    std::cout << current << "\n";
}
