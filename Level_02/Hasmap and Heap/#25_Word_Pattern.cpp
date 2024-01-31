#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> stringSplit(string &s, char delim) {
    vector<string> ans;
    string str = "";

    for (auto &ch : s) {
        if (ch != delim) {
            str += ch;
        } else {
            ans.push_back(str);
            str = "";
        }
    }

    ans.push_back(str);

    return ans;
}

bool wordPattern(string p, string s) {
    cout << s << endl;
    vector<string> words = stringSplit(s, ' ');

    for (auto &val : words)
        cout << val << " ";

    if (words.size() != p.length())
        return false;
    int n = p.length();

    unordered_map<char, string> m1;
    unordered_map<string, bool> m2;

    for (int i = 0; i < n; i++) {
        char ch = p[i];
        string str = words[i];

        if (m1.count(ch)) {
            if (m1[ch] != str)
                return false;
        } else {
            if (m2.count(str))
                return false;
            else {
                m1[ch] = str;
                m2[str] = true;
            }
        }
    }

    return true;
}

int main() {
    string p, s;
    cin >> p;
    getline(cin, s);

    cout << s << endl;

    cout << wordPattern(p, s);
    return 0;
}

// INPUT
// abba
// dog cat cat dog

// OUTPUT
// 1