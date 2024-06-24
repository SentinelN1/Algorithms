// Числа
#include <iostream>
#include <string>
#include <queue>
#include <map>

int main()
{
    std::string start, finish;
    std::cin >> start >> finish;
    std::map<std::string, std::string> m;
    std::queue<std::string> q;

    auto current(start);
    q.push(current);
    while (m[finish].empty())
    {
        int len = current.length();
        for (int i = 0; i < len; ++i)
        {
            for (char c = 'A'; c <= 'Z'; ++c)
            {
                auto s1(current);
                s1.insert(i, 1, c);
                if (m[s1].empty())
                {
                    m[s1] = current;
                    q.push(s1);
                }

                auto s2(current);
                if (s2[i] != c)
                {
                    s2[i] = c;
                }
                if (m[s2].empty())
                {
                    m[s2] = current;
                    q.push(s2);
                }
            }

            auto s3(current);
            s3.erase(i);
            if (m[s3].empty())
            {
                m[s3] = current;
                q.push(s3);
            }
        }

        q.pop();
        current = q.front();
    }

    int count = 0;
    current = finish;

    while (current != start)
    {
        ++count;
        current = m[current];
    }
    std::cout << count << "\n";
    return 0;
}
