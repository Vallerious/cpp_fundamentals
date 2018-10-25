#include <iostream>
#include <map>
#include <iomanip>
#include <math.h>

int main() {
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);

    char c;
    char dna[6];
    int idx = 1;
    std::map<int, int> occurences;

    while (true) {
        std::cin >> c;

        if (c =='.') {
            break;
        }

        dna[idx - 1] = c;

        if (idx == 5) {
            dna[5] = '\0';
            int integerEquivalent = 0;

            for (int i = 0; i < 5; i++) {
                int currentCharacterValue;

                if (dna[i] >= '0' && dna[i] <= '9') {
                    currentCharacterValue = dna[i] - 48;
                }
                else if (dna[i] >= 'a' && dna[i] <= 'z') {
                    currentCharacterValue = dna[i] - 87;
                }

                integerEquivalent += currentCharacterValue * std::pow(16, 5 - i - 1);
            }

            occurences[integerEquivalent]++;

            idx = 0;
        }

        idx++;
    }

    for (auto it = occurences.begin(); it != occurences.end(); it++) {
        if (it->second == 1) {
            std::cout << std::hex << it->first;
        }
    }

    return 0;
}