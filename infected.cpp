#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <algorithm>

int main()
{
    int n, m;
    std::cin >> n;
    std::map<int, std::string> dict;
    for (int i = 0; i < n; i++)
    {
        std::string str;
        int mac;
        std::cin >> str >> mac;
        dict[mac] = str;
    }

    std::cin >> m;
    std::map<int, int> connections;
    for (size_t i = 0; i < m; i++)
    {
        int from, to;
        std::cin >> from >> to;
        connections[from] = to;
        connections[to] = from;
    }

    std::map<int, bool> visited;
    std::queue<int> to_visit;
    std::vector<std::string> ans;

    int mac = connections.begin()->first;
    to_visit.push(mac);
    visited[mac] = true;
    while (!to_visit.empty())
    {
        int cur = to_visit.front();
        if (dict[cur].find("infected") != std::string::npos)
        {
            ans.push_back(dict[cur]);
        }
        for (auto i : connections)
        {
            if (!visited[i.second])
            {
                to_visit.push(i.second);
                visited[i.second] = true;
            }
        }
        to_visit.pop();
    }
    for (auto i : ans)
    {
        std::cout << i << std::endl;
    }
    return 0;
}