#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    std::ifstream input;
    input.open("input.txt");

    int n, k;
    input >> n >> k;
    // std::cin >> n >> k;
    std::vector<std::pair<long long int, int>> nums(n);
    for (int i = 0; i < n; i++)
    {
        input >> nums[i].first;
        // std::cin >> nums[i].first;
        nums[i].second = i;
    }
    if (input)
    {
        input.close();
    }
    std::sort(nums.begin(), nums.end());

    std::vector<long long int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[nums[i].second] = 1e9;
        int sum = 0;
        int left = std::max(0, i - k);
        int right = left;
        int count = 0;
        while (left <= i + 1)
        {
            while (count < k)
            {
                if (right != i)
                {
                    sum += std::abs(nums[i].first - nums[right].first);
                    ++count;
                }
                ++right;
            }

            if (count == k && sum < ans[nums[i].second])
            {
                ans[nums[i].second] = sum;
            }

            if (left != i)
            {
                --count;
                sum -= std::abs(nums[i].first - nums[left].first);
            }

            ++left;
        }
    }

    std::ofstream output;
    output.open("output.txt");
    for (int i = 0; i < n; i++)
    {
        output << ans[i] << ' ';
        // std::cout << ans[i] << ' ';
    }
    if (output)
    {
        output.close();
    }
}
