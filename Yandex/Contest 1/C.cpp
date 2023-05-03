#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<double> prices(N);
    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    vector<pair<int, int>> maxLeft(N);
    vector<pair<int, int>> maxRight(N);

    map<pair<int, int>, pair<int, int>> stored;
    for (int from = 0; from < N; ++from)
    {
        for (int to = from; to < N; ++to)
        {
            int left = from;
            int buy = left;
            int sell = left;
            double maxProfit = 1.0;
            for (int right = left; right <= to; ++right)
            {
                if (prices[right] >= prices[left])
                {
                    if (prices[right] / prices[left] > maxProfit)
                    {
                        buy = left;
                        sell = right;
                        maxProfit = prices[right] / prices[left];
                    }
                    continue;
                }
                else
                {
                    left = right;
                }
            }
            stored[{from, to}] = {buy, sell};
        }
    }

    int b1 = 0;
    int s1 = 0;
    int b2 = 0;
    int s2 = 0;
    double totalprofit = 1;
    for (int i = 0; i <= N; ++i)
    {
        auto tmp = prices[stored[{0, i}].first] * prices[stored[{0, i}].second] * prices[stored[{i, N}].first * prices[stored[{i, N}].second]];
        if (tmp > totalprofit)
        {
            totalprofit = tmp;
            b1 = stored[{0, i}].first;
            s1 = stored[{0, i}].second;
            b2 = stored[{i, N}].first;
            s2 = stored[{i, N}].second;
        }
    }
    if (b1 != s1 && b2 != s2)
    {
        cout << 2 << "\n";
        cout << b1 << " " << s1 << " " << b2 << " " << s2 << "\n";
    }
    else if (b1 != s1 && b2 == s2)
    {
        cout << 1 << "\n";
        cout << b1 << " " << s1 << "\n";
    }
    else if (b1 == s1 && b2 != s2)
    {
        cout << 1 << "\n";
        cout << b2 << " " << s2 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
    return 0;
}
