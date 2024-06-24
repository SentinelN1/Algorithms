// leetcode.com/problems/median-of-two-sorted-arrays

#include <iostream>
#include <vector>

// using namespace std;
using std::vector;

class Solution
{
public:
    double linearTime(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 == 0)
        {
            if (n2 % 2 == 1)
            {
                return nums2[n2 / 2];
            }
            else
            {
                return 0.5 * nums2[n2 / 2 - 1] + 0.5 * nums2[n2 / 2];
            }
        }

        if (n2 == 0)
        {
            if (n1 % 2 == 1)
            {
                return nums1[n1 / 2];
            }
            else
            {
                return 0.5 * nums1[n1 / 2 - 1] + 0.5 * nums1[n1 / 2];
            }
        }

        int n = n1 + n2;

        int lid, rid;
        if (n % 2 == 1)
        {
            // 0 1 2 3 4
            lid = n / 2;
            rid = n / 2;
        }
        else
        {
            // 0 1 2 3
            lid = n / 2 - 1;
            rid = n / 2;
        }

        int i = 0;
        int j = 0;

        double res = 0.0;
        while (i + j <= rid)
        {
            if (i < n1 && j < n2 && nums1[i] < nums2[j] || i < n1 && j >= n2)
            {
                if (n % 2 == 0)
                {
                    if (i + j == n / 2 - 1)
                    {
                        res = nums1[i] / 2.0;
                    }
                    if (i + j == n / 2)
                    {
                        return res + nums1[i] / 2.0;
                    }
                }
                else if (n % 2 == 1 && i + j == n / 2)
                {
                    return nums1[i];
                }
                i++;
            }
            else if (i < n1 && j < n2 && nums1[i] >= nums2[j] || i >= n1 && j < n2)
            {
                if (n % 2 == 0)
                {
                    if (i + j == n / 2 - 1)
                    {
                        res = nums2[j] / 2.0;
                    }
                    if (i + j == n / 2)
                    {
                        return res + nums2[j] / 2.0;
                    }
                }
                else if (n % 2 == 1 && i + j == n / 2)
                {
                    return nums2[j];
                }
                j++;
            }
        }
        return res;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();

        int nums1_left_bound_index = 0;
        int nums1_right_bound_index = m - 1;

        int nums1_left_median_index;
        int nums1_right_median_index;

        int n = nums2.size();

        int nums2_left_bound_index = 0;
        int nums2_right_bound_index = n - 1;

        int nums2_left_median_index;
        int nums2_right_median_index;

        double nums1_median_value, nums2_median_value;

        // std::cout << nums1_median_value << ", " << nums2_median_value << std::endl;
        int i = 0;
        while (i < 100)
        {
            if ((nums1_right_bound_index - nums1_left_bound_index + 1) % 2 == 0)
            {
                nums1_left_median_index = (nums1_right_bound_index - nums1_left_bound_index + 1) / 2 - 1;
                nums1_right_median_index = (nums1_right_bound_index - nums1_left_bound_index + 1) / 2;
            }
            else
            {
                nums1_left_median_index = (nums1_right_bound_index - nums1_left_bound_index) / 2;
                nums1_right_median_index = (nums1_right_bound_index - nums1_left_bound_index) / 2;
            }

            if ((nums2_right_bound_index - nums2_left_bound_index + 1) % 2 == 0)
            {
                nums2_left_median_index = (nums2_right_bound_index - nums2_left_bound_index + 1) / 2 - 1;
                nums2_right_median_index = (nums2_right_bound_index - nums2_left_bound_index + 1) / 2;
            }
            else
            {
                nums2_left_median_index = (nums2_right_bound_index - nums2_left_bound_index) / 2;
                nums2_right_median_index = (nums2_right_bound_index - nums2_left_bound_index + 1) / 2;
            }

            nums1_median_value = nums1[nums1_left_median_index] / 2.0 + nums1[nums1_right_median_index] / 2.0;
            nums2_median_value = nums2[nums2_left_median_index] / 2.0 + nums2[nums2_right_median_index] / 2.0;

            if (nums1_median_value == nums2_median_value)
            {
                return nums1_median_value;
            }
            else if (nums1_median_value < nums2_median_value)
            {
                nums1_left_bound_index = nums1_left_median_index;
                nums2_right_bound_index = nums2_right_median_index;
            }
            else
            {
                nums1_right_bound_index = nums1_right_median_index;
                nums2_left_bound_index = nums2_left_median_index;
            }

            std::cout << i << std::endl;
            std::cout << "[" << nums1[nums1_left_bound_index] << "; " << nums1[nums1_right_bound_index] << "]" << std::endl;
            std::cout << "[" << nums2[nums2_left_bound_index] << "; " << nums2[nums2_right_bound_index] << "]" << std::endl;
            std::cout << "---------------" << std::endl;
            i++;
        }

        return nums1_median_value / 2.0 + nums2_median_value / 2.0;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1;
    vector<int> nums2;
    double result;

    {
        nums1 = {1, 3};
        nums2 = {2};
        result = solution.linearTime(nums1, nums2);

        std::cout << "Test 1: ";
        if (result == 2.0)
        {
            std::cout << "passed" << std::endl;
        }
        else
        {
            std::cout << "failed" << std::endl;
        }
    }
    {
        nums1 = {1, 2};
        nums2 = {3, 4};
        result = solution.linearTime(nums1, nums2);
        std::cout << "Test 2: ";
        if (result == 2.5)
        {
            std::cout << "passed" << std::endl;
        }
        else
        {
            std::cout << "failed" << std::endl;
        }
    }
    {
        nums1 = {-55, -52, 43, 87};
        nums2 = {-88, -87, -67, -31, 6, 22, 44};
        result = solution.linearTime(nums1, nums2);
        std::cout << "Test 3: ";
        if (result == -31.0)
        {
            std::cout << "passed" << std::endl;
        }
        else
        {
            std::cout << "failed" << std::endl;
        }
    }
    {
        nums1 = {};
        nums2 = {1};
        result = solution.linearTime(nums1, nums2);
        std::cout << "Test 4: ";
        if (result == 1.0)
        {
            std::cout << "passed" << std::endl;
        }
        else
        {
            std::cout << "failed" << std::endl;
        }
    }
    {
        nums1 = {2, 2, 2, 2};
        nums2 = {2, 2, 2};
        result = solution.linearTime(nums1, nums2);
        std::cout << "Test 5: ";
        if (result == 2.0)
        {
            std::cout << "passed" << std::endl;
        }
        else
        {
            std::cout << "failed" << std::endl;
        }
    }
}
