// https://leetcode.com/problems/binary-search/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        if (nums[left] == target)
        {
            return left;
        }
        if (nums[right] == target)
        {
            return right;
        }
        if (nums[right] < target || target < nums[left])
        {
            return -1;
        }

        int middle = n / 2;
        while (left != right)
        {
            if (nums[middle] == target)
            {
                return middle;
            }
            if (nums[middle] < target)
            {
                left += (right - left + 1) / 2;
            }
            if (nums[middle] > target)
            {
                right -= (right - left + 1) / 2;
            }
            middle = (left + right) / 2;
        }

        if (nums[left] == target)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    const int target = 9;
    // vector<int> nums = {-1, 0, 3, 5, 9, 12};
    // const int target = 2;
    Solution solution;
    auto ans = solution.search(nums, target);
    std::cout << ans;
}
