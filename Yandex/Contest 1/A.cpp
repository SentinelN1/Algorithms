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
    vector<int> characters(N);
    map<int, int> m; // char to row map

    for (int i = 0; i < N; i++)
    {
        cin >> characters[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> m[characters[i]];
    }

    int K;
    cin >> K;

    int prev;
    cin >> prev;

    int ans = 0;
    for (int i = 1; i < K; i++)
    {
        int cur;
        cin >> cur;
        if (m[prev] != m[cur])
        {
            ans++;
        }
        prev = cur;
    }
    cout << ans;
    return 0;
}