#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> alphabet(n);
    int maxgood = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> alphabet[i];
        if (i != 0)
        {
            maxgood += min(alphabet[i - 1], alphabet[i]);
        }
    }
    cout << maxgood;
    return 0;
}
