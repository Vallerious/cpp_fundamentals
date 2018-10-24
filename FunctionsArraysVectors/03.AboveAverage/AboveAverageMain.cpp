#include <iostream>
#include <vector>

int runningSum(int nextNumber) {
    static int sum = 0;

    sum += nextNumber;

    return sum;
}

int calculateAverage(int sum, int n) {
    return sum / n;
}

std::vector<int> filterSmallerThan(const std::vector<int>& numbers, int n, int compareToThis) {
    std::vector<int> largerThanAverage;

    for (int i = 0; i < n; i++) {
        if (numbers[i] >= compareToThis) {
            largerThanAverage.push_back(numbers[i]);
        }
    }

    return largerThanAverage;
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> numbers;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;

        numbers.push_back(c);
        sum = runningSum(c);
    }

    int avg = calculateAverage(sum, n);

    std::vector<int> largerThanAverage = filterSmallerThan(numbers, n, avg);

    for (int num : largerThanAverage) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}