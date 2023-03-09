#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> histogram(n);
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> histogram[i];
    }
    for (int start = 0; start < n; start++)
    {
        for (int finish = start; finish < n; finish++)
        {
            int tmp = histogram[start];
            for (int index = start; index <= finish; index++)
            {
                tmp = min(histogram[index], tmp);
            }
            area = max(area, tmp * (finish - start + 1));
        }
    }
    cout << area;
}