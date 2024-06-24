#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> matrix((n + 1) * (m + 1));
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0)
            {
                matrix[i * (m + 1) + j] = 0;
            }
            else
            {
                int tmp;
                cin >> tmp;
                tmp += matrix[(i - 1) * (m + 1) + j];
                tmp += matrix[i * (m + 1) + (j - 1)];
                tmp -= matrix[(i - 1) * (m + 1) + (j - 1)];
                matrix[i * (m + 1) + j] = tmp;
            }
        }
    }
    for (int i = 0; i < k; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << matrix[x2 * (m + 1) + y2] - matrix[(x1 - 1) * (m + 1) + y2] - matrix[x2 * (m + 1) + (y1 - 1)] + matrix[(x1 - 1) * (m + 1) + (y1 - 1)] << endl;
    }
    return 0;
}