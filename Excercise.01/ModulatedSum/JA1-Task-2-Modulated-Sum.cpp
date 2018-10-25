#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    const int MAX_INPUT_COUNT = 100;
    int sums[MAX_INPUT_COUNT];

    for (int i = 0; i < MAX_INPUT_COUNT; i++) {
        sums[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            std::cin >> val;
            sums[j] += val;
        }
    }

    int modValue;
    std::cin >> modValue;

    for (int i = 0; i < m; i++) {
        std::cout << sums[i] % modValue << " ";
    }

    return 0;
}