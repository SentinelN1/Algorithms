// Дан массив целых чисел и число X, нужно вернуть минимальный по размеру подмассив, такой что сумма его элементов не меньше X
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n;
    std::vector<int> nums(n);
    std::queue<int> que;
    for (auto &i : nums)
    {
        std::cin >> i;
    }
    std::cin >> x;
    std::sort(nums.begin(), nums.end());
    
    int sum = 0;
    int index = n - 1;
    while(sum <= x) {
        if (sum <= x) {
            que.push(nums[index]);
            sum += nums[index];
            --index;
        }
    }
    return 0;
}