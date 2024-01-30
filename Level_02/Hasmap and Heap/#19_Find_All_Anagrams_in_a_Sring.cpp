#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> arr;

void removeFromMap(map<char, int> &m, char ch) {
    if (m[ch] == 1)
        m.erase(ch);
    else
        m[ch]--;
}

int count(string &s1, string &s2) {
    int n1 = s1.length();
    int n2 = s2.length();

    map<char, int> m1;
    map<char, int> m2;

    // pattern map of string-s2
    for (auto &val : s2)
        m2[val]++;

    int cnt = 0, i = -1, j = -1;

    while (true) {
        bool f1 = false, f2 = false;

        // acquire
        while (i < n1 - 1) {
            f1 = true;
            i++;
            m1[s1[i]]++;

            // we need to maintain a window-size equal to that of the s2-length
            if (i - j == n2)
                break;
        }

        // release
        while (j < i) {
            f2 = true;
            if (m1 == m2) {
                cnt += 1;
                arr.push_back(j + 1);
            }

            j++;
            removeFromMap(m1, s1[j]);

            // as soon as the window-size is becomes less than the s2-length
            // stop releasing
            if (i - j < n2)
                break;
        }

        if (f1 == false && f2 == false)
            break;
    }

    return cnt;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << count(s1, s2) << endl;

    for (auto &val : arr)
        cout << val << " ";
    cout << endl;
    return 0;
}