// ============================ GIVES THE WRONG OUTPUT =======================

#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

string maxWindowSubstring(string &str) {

    string ans = "";
    set<char> s;
    for (auto &val : str)
        s.insert(val);
    int dmcnt = s.size();

    int i = -1, j = -1, n = str.length();

    unordered_map<char, int> m;

    while (i < n) {
        // Acquire
        if (m.size() < dmcnt) {
            i++;
            m[str[i]]++;
        }

        // Release
        while (m.size() == dmcnt) {
            int len = i - j;

            j++;
            m[str[j]]--;
            if (m[str[j]] == 0)
                m.erase(str[j]);

            // pans = potential answer
            string pans = str.substr(j, len);
            if (ans.length() == 0 || pans.length() < ans.length()) {
                ans = pans;
            }
        }
    }

    return ans;
}

// instead of returning the string we are returing the length of the smallest
// string here
int pepCodingSolution(string &str) {
    int ans = 0;

    set<char> s;
    for (auto &ch : str)
        s.insert(ch);
    int dmcnt = s.size();

    int i = -1, j = -1, n = str.length();
    unordered_map<char, int> m;

    while (true) {
        bool f1 = false, f2 = false;

        // acquire till invalid
        while (i < n - 1 && m.size() < dmcnt) {
            f1 = true;

            i++;
            char ch = str[i];
            m[ch]++;
        }

        // collect answer and release

        while (j < i && m.size() == dmcnt) {
            f2 = true;

            int len = i - j;
            if (ans == 0 || len < ans)
                ans = len;

            j++;
            if (m[str[j]] == 1)
                m.erase(str[j]);
            else
                m[str[j]]--;
        }

        if (f1 == false && f2 == false)
            break;
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    // cout << maxWindowSubstring(str);
    cout << pepCodingSolution(str);
    return 0;
}