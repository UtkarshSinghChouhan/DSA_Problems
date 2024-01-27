#include <iostream>
#include <unordered_map>
using namespace std;

void removeFromMap(unordered_map<char, int> &m, char ch) {
    if (m[ch] == 1)
        m.erase(ch);
    else
        m[ch]--;
}

// Handling for  k = 1
int countforkEqualtoOne(string &str, int k) {
    int cnt = 0;
    int n = str.length();
    int i = -1, j = -1;
    unordered_map<char, int> m;

    while (true) {
        bool f1 = false, f2 = false;

        // acquire
        while (i < n - 1) {
            f1 = true;
            i++;
            m[str[i]]++;

            if (m.size() == 2) {
                removeFromMap(m, str[i]);
                i--;
                break;
            }
        }

        // release
        while (j < i) {
            f2 = true;
            if (m.size() == 1)
                cnt += (i - j);

            j++;
            removeFromMap(m, str[j]);

            if (m.size() == 0)
                break;
        }

        if (f1 == false && f2 == false)
            break;
    }

    return cnt;
}

int count(string &str, int k) {
    if (k == 1)
        return countforkEqualtoOne(str, k);

    int n = str.length();
    int cnt = 0;
    int ib = -1, is = -1, j = -1;
    unordered_map<char, int> mb;
    unordered_map<char, int> ms;

    while (true) {
        bool f1 = false, f2 = false, f3 = false;

        // acquire for map big
        while (ib < n - 1) {
            f1 = true;
            ib++;
            mb[str[ib]]++;

            if (mb.size() == k + 1) {
                removeFromMap(mb, str[ib]);
                ib--;
                break;
            }
        }

        // acquire for map small
        while (is < ib) {
            f2 = true;
            is++;
            ms[str[is]]++;

            if (ms.size() == k) {
                removeFromMap(ms, str[is]);
                is--;
                break;
            }
        }

        // release

        while (j < is) {
            f3 = true;
            if (mb.size() == k && ms.size() == k - 1)
                cnt += (ib - is);

            j++;
            removeFromMap(mb, str[j]);
            removeFromMap(ms, str[j]);

            if (mb.size() < k || ms.size() < k - 1)
                break;
        }

        if (f1 == false && f2 == false && f3 == false)
            break;
    }

    return cnt;
}

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;

    cout << count(str, k);
    return 0;
}

// INPUT - 1
// abcabdabbcfa
// k = 3
// OUTPUT - 2
// 19

// INPUT-2
// aabbbcca
// 1

// OUPUT - 2
// 13