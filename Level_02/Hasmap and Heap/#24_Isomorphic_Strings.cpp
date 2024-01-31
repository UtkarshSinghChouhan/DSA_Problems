#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string &s1, string &s2) {
    if (s1.length() != s2.length())
        return false;

    unordered_map<char, char> m1;
    unordered_map<char, bool> m2;

    int n = s1.length();

    for (int i = 0; i < n; i++) {
        char c1 = s1[i];
        char c2 = s2[i];

        // if character-1 exists in map-m1
        if (m1.count(c1)) {
            // if c1 is mapped but not with c2
            if (m1[c1] != c2)
                return false;
        }

        // if c1 is not in map-m1
        else {
            // since c1 is not mapped in  map-m1 but c2 is already mapped in
            // map-m2
            if (m2.count(c2)) {
                return false;
            }
            // if both c1 is not in map-m1 and c2 is not in map-m2
            else {
                m1[c1] = c2;
                m2[c2] = true;
            }
        }
    }

    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << isIsomorphic(s1, s2);
    return 0;
}

// INPUT
//  abacba
//  xyxzyx

// OUTPUT
// 1

// CASE - 2
// INPUT
// abacba
// xyxzyw

// OUTPUT
// 0

// CASE - 3
// INPUT
// abacba
// xyxzyw

// OUTPUT
// 0