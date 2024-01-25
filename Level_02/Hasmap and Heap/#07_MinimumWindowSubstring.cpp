#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string minWindowSubstring(string &str1, string &str2) {
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
            string pans = str1.substr(j, len); // pans = potential answer

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

string pepCodingSolution(string s1, string s2) {
    string ans = "";
    int mcnt = 0, dmcnt = s2.length();
    unordered_map<char, int> mp2;
    for (auto &ch : s2)
        mp2[ch]++;

    unordered_map<char, int> mp1;
    int i = -1, j = -1, n = s1.length();
    while (true) {
        bool f1 = false, f2 = false;

        // acquire
        while (i < n - 1 && mcnt < dmcnt) {
            f1 = true;

            i++;
            char ch = s1[i];
            mp1[ch]++;

            if (mp1[ch] <= mp2[ch])
                mcnt++;
        }

        // release and collect answers
        while (j < i && mcnt == dmcnt) {
            f2 = true;

            int len = i - j;
            j++;
            string pans = s1.substr(j, len);

            if (ans.length() == 0 || pans.length() < ans.length())
                ans = pans;

            char ch = s1[j];
            mp1[ch]--;
            if (mp1[ch] < mp2[ch])
                mcnt--;

            if (mp1[ch] == 0)
                mp1.erase(ch);
        }

        if (f1 == false && f2 == false)
            break;
    }

    return ans;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    // cout << minWindowSubstring(str1, str2);
    cout << pepCodingSolution(str1, str2);
    return 0;
}