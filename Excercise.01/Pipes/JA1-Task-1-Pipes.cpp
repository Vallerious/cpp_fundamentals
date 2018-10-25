#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    short int n;
    std::cin >> n;

    int checkup[500];

    for (short int i = 0; i < n; i++) {
        std::cin >> checkup[i];
    }

    for (short int i = 0; i < n; i++) {
        int installationValue;
        std::cin >> installationValue;

        int damagePerYear = installationValue - checkup[i];
        int yearsLeft = checkup[i] / damagePerYear;
        int totalLifetime = yearsLeft + 1;

        std::cout << totalLifetime << " ";
    }

    return 0;
}