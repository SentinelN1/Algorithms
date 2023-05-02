#define ALPHABET_SIZE 26

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main()
{
    const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    int N, K;
    cin >> N >> K;

    string str;
    str.reserve(N);
    cin >> str;

    vector<int> position(N);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        position[i] = tmp - 1;
    }

    vector<int> offset(N);
    for (int i = 0; i < N; i++)
    {
        cin >> offset[i];
    }

    unsigned long long int totalPower = 0;
    for (int i = 0; i < N; ++i)
    {
        int index = i;
        char curChar = str[index];

        map<char, int> visited;
        unsigned long long int prevPower = 0;
        for (int j = 0; j < K; j++)
        {
            unsigned long long int curPower = prevPower;
            char nextChar = char(int('a') + (int(curChar) - int('a') + visited[curChar] * offset[index]) % ALPHABET_SIZE);
            if (visited[nextChar] == 0)
            {
                curPower++;
            }
            visited[curChar]++;

            index = position[index];
            curChar = str[index];
            totalPower += curPower;
            prevPower = curPower;
        }
    }
    cout << totalPower << "\n";

    return 0;
}
