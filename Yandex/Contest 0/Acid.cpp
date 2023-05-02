#include <vector>
#include <iostream>

int main() {
	int steps = 0;
	int n;
	std::cin >> n;
	std::vector<unsigned long long int> nums(n);
	for (int i = 0; i < n; ++i) {
    	std::cin >> nums[i];
    	if (i > 0) {
	        if (nums[i] > nums[i - 1]) {
    	    	++steps;
            }
        	if (nums[i] < nums[i - 1]) {
            	std::cout << -1;
            	return 0;
            }
    	}
    }
    std::cout << steps;
    return 0;
}