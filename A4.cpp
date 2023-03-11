// Контрольная работа
#include <iostream>

using namespace std;

int main()
{
    int n, k, r, s;
    cin >> n >> k >> r >> s;
    int p1 = (r - 1) * 2 + s;
    int r1 = -1;
    int r2 = -1;
    if (p1 + k <= n)
    {
        r1 = (p1 + k - 1) / 2 + 1;
    }
    if (p1 - k > 0)
    {
        r2 = (p1 - k - 1) / 2 + 1;
    }
    if (r1 == -1 && r2 == -1)
    {
        cout << -1;
        return 0;
    }
    if (r1 != -1 && r2 != -1)
    {
        if (r2 - r <= r - r1)
        {
            cout << (p1 + k - 1) / 2 + 1 << " " << (p1 + k - 1) % 2 + 1;
            return 0;
        }
        cout << (p1 - k - 1) / 2 + 1 << " " << (p1 - k - 1) % 2 + 1;
        return 0;
    }
    if (r1 != -1)
    {
        cout << (p1 + k - 1) / 2 + 1 << " " << (p1 + k - 1) % 2 + 1;
        return 0;
    }
    cout << (p1 - k - 1) / 2 + 1 << " " << (p1 - k - 1) % 2 + 1;
    return 0;
}
