#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    map<map<char, int>, vector<string>> mb;

    for (auto &str : strs) {
        map<char, int> m;
        for (auto &ch : str)
            m[ch]++;

        if (mb.count(m)) {
            mb[m].push_back(str);
        } else {
            vector<string> v;
            v.push_back(str);
            mb[m] = v;
        }
    }

    for (auto &[key, val] : mb) {
        ans.push_back(val);
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

    vector<vector<string>> ans = groupAnagrams(strs);

    for (auto &v : ans) {
        for (auto &str : v) {
            cout << str << " ";
        }

        cout << endl;
    }
    return 0;
}

// INPUT
// 8
// abcc
// acbc
// badc
// abcd
// dabb
// babd
// dbca
// cabc

// OUTPUT
// badc abcd dbca
// abcc acbc cabc
// dabb babd