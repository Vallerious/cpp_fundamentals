#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> takeVectorFromConsole() {
    int n;
    std::cin >> n;
    std::vector<int> nums;

    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        nums.push_back(c);
    }

    return nums;
}

int findClosestAbsoluteDifference(const std::vector<int>& nums) {
    int minDifference = std::abs(std::pow(2, (sizeof(int) * 8) - 1) - 1);
    int len = nums.size();

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int diff = std::abs(nums[i] - nums[j]);

            if (diff < minDifference) {
                minDifference = diff;
            }
        }
    }

    return minDifference;
}

int main() {
    std::vector<int> numbers = takeVectorFromConsole();

    int minDiff = findClosestAbsoluteDifference(numbers);

    std::cout << minDiff << std::endl;

    return 0;
}