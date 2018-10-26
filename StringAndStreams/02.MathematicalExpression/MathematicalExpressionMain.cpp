#include <iostream>
#include <string>
#include <sstream>

// Check for valid brackets in mathematical expression.
int main() {
    using namespace std;

    int balance = 0;
    char c;
    string result = "incorrect";
    string line;
    getline(cin, line);
    istringstream lineIn(line);

    while (lineIn >> c) {
        if (c == '(') {
            balance++;
        }
        else if (c == ')') {
            balance--;

            if (balance <= 0) {
                break;
            }
        }
    }

    if (balance == 0) {
        result = "correct";
    }

    cout << result << endl;

    return 0;
}