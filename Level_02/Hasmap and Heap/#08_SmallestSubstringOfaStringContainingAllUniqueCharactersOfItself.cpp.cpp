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
        while (j < i && m.size() == dmcnt) {
            int len = i - j;

            j++;
            m[str[j]]--;
            if (m[str[j]] == 0)
                m.erase(str[j]);

            string pans = str.substr(j, len);
            if (ans.length() == 0 || pans.length() < ans.length()) {
                ans = pans;
                cout << ans << endl;
                ;
            }
        }
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << maxWindowSubstring(str);
    return 0;
}