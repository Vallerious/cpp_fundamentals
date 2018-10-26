#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Receiving numbers and string from the console input, separate the numbers from the words.
int main() {
    using namespace std;

    string line;
    getline(cin, line);
    istringstream lineIn(line);
    vector<string> words;
    vector<int> numbers;
    string part;

    while (lineIn >> part) {
        istringstream partIn(part);
        int num;

        if (partIn >> num) {
            numbers.push_back(num);
        }
        else {
            words.push_back(part);
        }
    }

    int sum = 0;

    for (int n : numbers) {
        sum += n;
    }

    cout << sum << endl;

    for (string w : words) {
        cout << w << " ";
    }

    return 0;
}