#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithoutRepeatingCharacters(string &str) {
    int ans = 0;
    int n = str.length();
    unordered_map<char, int> m;
    int i = -1, j = -1;

    while (true) {
        bool f1 = false;
        bool f2 = false;
        // acquire
        while (i < n - 1) {
            f1 = true;
            i++;

            m[str[i]]++;

            if (m[str[i]] == 2)
                break;
            else {
                int len = i - j;
                ans = max(ans, len);
            }
        }

        // release
        while (j < i) {
            f2 = true;
            j++;
            m[str[j]]--;

            if (m[str[j]] == 1)
                break;
        }

        if (!f1 && !f2)
            break;
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << longestSubstringWithoutRepeatingCharacters(str);
    return 0;
}