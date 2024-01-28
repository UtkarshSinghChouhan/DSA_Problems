#include <iostream>
#include <unordered_map>
using namespace std;

int removeFromMap(unordered_map<char, int> &m, char ch) {
    if (m[ch] == 1)
        m.erase(ch);
    else
        m[ch]--;
}

int countSubstr(string &str, int k) {
    int n = str.length();
    int ans = 0, i = -1, j = -1;
    unordered_map<char, int> m;

    while (true) {

        // acquiring
        while (i < n - 1) {
            i++;
            m[str[i]]++;

            if (m.size() <= k) {
                ans += i - j;
            } else {
                break;
            }
        }

        // Inorder to breakout from the outer loop
        if (i == n - 1 && m.size() == k)
            break;

        // releasing
        while (j < i) {
            j++;
            removeFromMap(m, str[j]);

            if (m.size() == k) {
                ans += i - j;
                break;
            }
        }
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;

    cout << countSubstr(str, k);

    return 0;
}

// INPUT
// aabcbcdbca
// 2

// OUTPUT
// 23