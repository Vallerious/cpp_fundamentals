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

int main() {
    std::vector<int> numbers = takeVectorFromConsole();
    const int NUM_COUNT = 10;

    int occurences[NUM_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int maxOccurenceNumber = 0;

    for (int i = 0; i < numbers.size(); i++) {
        occurences[numbers[i]]++;

        if (occurences[numbers[i]] > maxOccurenceNumber) {
            maxOccurenceNumber = occurences[numbers[i]];
        }
    }

    for (int i = 0; i < NUM_COUNT; i++) {
        if (occurences[i] == maxOccurenceNumber) {
            std::cout << i << " ";
        }
    }

    return 0;
}