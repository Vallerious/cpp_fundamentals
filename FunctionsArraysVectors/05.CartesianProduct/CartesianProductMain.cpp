#include <iostream>
#include <vector>

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

std::vector<int> generateCartesianProducts(const std::vector<int>& nums) {
    int len = nums.size();
    std::vector<int> cartesianProducts;
    cartesianProducts.reserve(len * len);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cartesianProducts.push_back(nums[i] * nums[j]);
        }
    }

    return cartesianProducts;
}

int main() {
    std::vector<int> numbers = takeVectorFromConsole();

    std::vector<int> cartesianProducts = generateCartesianProducts(numbers);

    return 0;
}