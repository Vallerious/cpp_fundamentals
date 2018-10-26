#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int parseInteger(const std::string& str) {
    std::istringstream strIn(str);
    int n;
    if (!(strIn >> n)) {
        // kaboom!!
    }

    return n;
}

std::vector<int> cleanNumbersInput(const std::string& str) {
    vector<int> numbers;
    istringstream lineIn(str);

    string supposedNumber;
    while (lineIn >> supposedNumber) {
        ostringstream numberIn;

        for (int i = 0; i < supposedNumber.size(); i++) {
            if (isdigit(supposedNumber[i])) {
                numberIn << supposedNumber[i];
            }
        }

        int n = parseInteger(numberIn.str());

        numbers.push_back(n);
    }

    return numbers;
}

// Extract numbers from jibberish text and finds the maximum number amongst.
int main() {
    string line;
    getline(cin, line);

    vector<int> numbers = cleanNumbersInput(line);
    int max = *max_element(numbers.begin(), numbers.end());

    cout << max << endl;

    return 0;
}