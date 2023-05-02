#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
    int N, X;
    long long int T;
    cin >> N >> X >> T;
    map<int, list<int>> nums;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        nums[abs(tmp - X)].push_back(i + 1);
    }
    int count = 0;
    list<int> lst;
    for (auto i : nums)
    {
        for (auto j : i.second)
        {
            if (T >= i.first)
            {
                T -= i.first;
                lst.push_back(j);
                count++;
            }
            else
            {
                cout << count << "\n";
                for (auto k : lst)
                {
                    cout << k << " ";
                }
                return 0;
            }
        }
    }
    cout << count << "\n";
    for (auto k : lst)
    {
        cout << k << " ";
    }
    return 0;
}
