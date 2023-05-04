#include <fstream>
#include <vector>
#include <stack>

int main()
{
    long long int n;
    std::ifstream ifs;
    std::ofstream ofs;
    ifs.open("input.txt");
    ofs.open("output.txt");
    ifs >> n;

    std::stack<std::pair<size_t, long long int>> stair;
    stair.push({0, -1});

    long long int maxArea = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        long long int cur = 0;
        if (i <= n)
        {
            ifs >> cur;
        }
        int j = i;

        while (cur <= stair.top().second)
        {
            auto tmp = stair.top();
            j = tmp.first;
            maxArea = std::max(maxArea, (i - j) * tmp.second);
            stair.pop();
        }
        stair.push({j, cur});
    }

    ofs << maxArea;
    ifs.close();
    ofs.close();
}
