#include <iostream>
#include <unordered_map>

using namespace std;

int removeFromMap(unordered_map<char, int> &m, char ch) {
    if (m[ch] == 1)
        m.erase(ch);
    else
        m[ch]--;
}

int longestSubStr(string &str, int k) {
    int n = str.length();
    int ans = 0, i = -1, j = -1;
    unordered_map<char, int> m;

    while (true) {
        bool f1 = false, f2 = false;

        // acquiring
        while (i < n - 1) {
            f1 = true;

            i++;
            m[str[i]]++;

            if (m.size() <= k) {
                int len = i - j; // this is the length of the potential answer
                ans = max(ans, len);
            } else if (m.size() > k) {
                break;
            }
        }

        // releasing
        while (j < i) {
            f2 = true;

            j++;
            removeFromMap(m, str[j]);

            if (m.size() == k)
                break;
        }

        if (f1 == false && f2 == false)
            break;
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;

    cout << longestSubStr(str, k);

    return 0;
}

// INPUT-1
// ddacbbaccdedacebb
// 3

// OUTPUT-1
// 7(acbbacc)

// INPUT-2
// aabcbcdbca
// 3

// OUTPUT-2
// 4(bcbc)