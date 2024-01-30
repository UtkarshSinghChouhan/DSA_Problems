#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string getKey(string &str) {
    string key = "";

    for (int i = 1; i < str.length(); i++) {
        int diff = str[i] - str[i - 1];

        if (diff < 0)
            diff += 26;

        key += to_string(diff) + "#";
    }

    key += "*";

    return key;
}

vector<vector<string>> groupShiftedStrings(vector<string> &strs) {
    vector<vector<string>> ans;

    unordered_map<string, vector<string>> m;

    for (auto &str : strs) {
        string key = getKey(str);

        if (m.count(key)) {
            m[key].push_back(str);
        } else {
            vector<string> v;
            v.push_back(str);
            m[key] = v;
        }
    }

    for (auto &[key, v] : m) {
        ans.push_back(v);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    vector<vector<string>> ans = groupShiftedStrings(strs);

    for (auto &v : ans) {
        for (auto &str : v) {
            cout << str << " ";
        }

        cout << endl;
    }
    return 0;
}

// INPUT
// 9
// acd
// dfg
// wyz
// yab
// mop
// bdfh
// a
// x
// moqs

// OUTPUT
// a x
// acd dfg wyz yab mop
// bdfh moqs