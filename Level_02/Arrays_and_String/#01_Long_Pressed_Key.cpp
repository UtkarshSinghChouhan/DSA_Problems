#include <iostream>
using namespace std;

bool check(string name, string typed) {
    int n = name.length(), m = typed.length();
    if (n > m)
        return false;

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (name[i] == typed[j]) {
            i++;
            j++;
        } else if (i > 0 && typed[j] == name[i - 1]) {
            j++;
        } else {
            return false;
        }
    }

    while (j < m) {
        if (typed[j] != name[i - 1])
            return false;
        j++;
    }

    if (i < n)
        return false;

    return true;
}

int main() {
    string name, typed;
    cin >> name >> typed;

    cout << check(name, typed);
    return 0;
}