#include <iostream>
#include <string>

int main() {
    using namespace std;

    string firstArrayLine;
    getline(cin, firstArrayLine);

    string secondArrayLine;
    getline(cin, secondArrayLine);

    if (firstArrayLine == secondArrayLine) {
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }

    return 0;
}