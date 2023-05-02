// Написать фунцкию, которая находит в массиве второй максимум.
#include <vector>
#include <iostream>

int SecondMax(const std::vector<int> &nums) {
    int n = nums.size();
    int first = std::max(nums[0], nums[1]);
    int second = std::min(nums[0], nums[1]);
    for (int i = 2; i < n; ++i)
    {
        if (nums[i] > second) {
            second = nums[i];
        }
        if (nums[i] > first) {
            auto tmp = first;
            first = nums[i];
            second = tmp;
        }
    }
    return second;
}

int main() {
    std::vector<int> vec = {2, 7, 7, -3, 0, 7};
    std::cout << SecondMax(vec);
    return 0;
}
