#include <iostream>
#include <unordered_map>

using namespace std;

bool check(string &s1, string &s2, int k) {
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 != n2)
        return false;

    int sum = 0;

    unordered_map<char, int> m;
    for (auto &val : s1)
        m[val]++;

    for (auto &val : s2) {
        if (m.count(val) && m[val] != 0) {
            m[val]--;
        }
    }

    for (auto &[key, val] : m) {
        if (val > 0)
            sum += val;
    }

    return sum <= k;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int k;
    cin >> k;

    cout << check(s1, s2, k);
    return 0;
}

// INPUT
// aabbbc
// badaba
// 2

// OUTPUT
// true