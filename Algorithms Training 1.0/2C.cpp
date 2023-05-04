#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    int ans = nums[0];
    for (auto &cur : nums)
    {
        if (abs(cur - target) < abs(ans - target))
        {
            ans = cur;
        }
    }
    cout << ans;
}