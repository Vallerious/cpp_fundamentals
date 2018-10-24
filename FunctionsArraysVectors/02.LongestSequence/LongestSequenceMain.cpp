#include <iostream>
#include <vector>

std::vector<int> findLongestEqualSequence(const std::vector<int>& numbers, int n) {
    if (n < 2 || numbers.size() < 2) {
        return numbers;
    }

    int maxCount = 1;
    int count = 1;
    std::vector<int> seq{ numbers[0] };
    std::vector<int> maxSeq;

    for (int i = 1; i < n; i++) {
        if (numbers[i] == numbers[i - 1]) {
            count++;
            seq.push_back(numbers[i]);

            if (count >= maxCount) {
                maxCount = count;
                maxSeq.clear();
                maxSeq = seq;
            }
        }
        else {
            count = 1;
            seq.clear();
            seq.push_back(numbers[i]);
        }
    }

    return maxSeq;
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> allNumbers;

    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;

        allNumbers.push_back(c);
    }

    std::vector<int> maxSeq = findLongestEqualSequence(allNumbers, n);

    return 0;
}