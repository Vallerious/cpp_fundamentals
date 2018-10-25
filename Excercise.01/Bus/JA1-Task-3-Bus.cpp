#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    int busses[20];

    for (int i = 0; i < n; i++) {
        std::cin >> busses[i];
    }

    int trainLeaveTime;
    std::cin >> trainLeaveTime;

    int smallestDiff = INT_MAX;
    int smallestIdx = -1;

    for (int i = 0; i < n; i++) {
        int diff;

        if (trainLeaveTime < busses[i]) {
            diff = 2400 - busses[i] + trainLeaveTime;
        }
        else {
            diff = trainLeaveTime - busses[i];
        }

        if (diff < smallestDiff) {
            smallestDiff = diff;
            smallestIdx = i;
        }
    }

    std::cout << smallestIdx + 1;

    return 0;
}