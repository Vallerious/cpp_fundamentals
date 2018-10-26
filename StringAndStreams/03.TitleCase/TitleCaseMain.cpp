#include <iostream>
#include <string>
#include <sstream>

// Basically, make every word in a sentence Uppercase.
int main() {
    using namespace std;

    string sentence;
    getline(cin, sentence);

    sentence[0] = toupper(sentence[0]);

    for (int i = 1; i < sentence.size(); i++) {
        if (!isalpha(sentence[i - 1])) {
            sentence[i] = toupper(sentence[i]);
        }
    }

    cout << sentence << endl;

    return 0;
}