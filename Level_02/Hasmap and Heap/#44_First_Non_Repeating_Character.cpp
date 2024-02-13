#include <iostream>
#include <map>
using namespace std;

int firstNonRepeatingCharacter(string &str) {
    map<char, int> m;
    int n = str.length();
    for (auto &ch : str) {
        m[ch]++;
    }

    for (int i = 0; i < n; i++) {
        if (m[str[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string str;
    cin >> str;

    cout << firstNonRepeatingCharacter(str);

    return 0;
}