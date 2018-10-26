#include <iostream>
#include <string>
#include <sstream>

bool replaceAll(std::string& str, const std::string& from, const std::string& to) {
    int idx = str.find(from);

    if (idx == std::string::npos) {
        return false;
    }

    while (idx != std::string::npos) {
        str.erase(idx, from.size());
        str.insert(idx, to);
        idx = str.find(from, idx + 1);
    }

    return true;
}

// Replace all occurences of one word with another in sentence.
int main() {
    using namespace std;
    string sentence, needle, replacement;

    getline(cin, sentence);
    getline(cin, needle);
    getline(cin, replacement);

    replaceAll(sentence, needle, replacement);

    return 0;
}