#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Your task here is to find the longest noise in a number.
// Input: 5bbbb3 1f a0aaa f1fg3
// Output: aaaa

using namespace std;

vector<string> parseNoiseFromSignal(const string& str) {
    vector<string> noise;

    istringstream strIn(str);
    string part;

    while (strIn >> part) {
        ostringstream alphaOut;

        for (int i = 0; i < part.size(); i++) {
            if (!isdigit(part[i])) {
                alphaOut << part[i];
            }
        }

        noise.push_back(alphaOut.str());
    }

    return noise;
}

int main() {
    string line;
    getline(cin, line);

    vector<string> noise = parseNoiseFromSignal(line);
    string min = *min_element(noise.begin(), noise.end());

    if (min.empty()) {
        cout << "no noise" << endl;
    }
    else {
        cout << min << endl;
    }

    return 0;
}