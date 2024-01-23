#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string maxWindowSubstring(string &str1, string &str2) {
    string ans = "";
    int i = -1, j = -1, n = str1.length(), mcnt = 0, dmct = str2.length();

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for (auto &val : str2)
        mp2[val]++;

    while (i < n) {
        // acquire
        if (mcnt < dmct) {
            i++;

            mp1[str1[i]]++;

            if (mp2.find(str1[i]) != mp2.end() && mp1[str1[i]] <= mp2[str1[i]])
                mcnt++;
        }

        // release
        while (mcnt == dmct) {
            int len = i - j;
            j++;
            string pans = str1.substr(j, len);

            if (ans.length() == 0 || pans.length() < ans.length())
                ans = pans;

            mp1[str1[j]]--;

            if (mp1[str1[j]] < mp2[str1[j]])
                mcnt--;

            if (mp1[str1[j]] == 0)
                mp1.erase(str1[j]);
        }
    }

    return ans;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << maxWindowSubstring(str1, str2);
    return 0;
}