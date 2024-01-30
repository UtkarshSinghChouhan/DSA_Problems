#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<int> anagramMapping(vector<int> &a1, vector<int> &a2) {
    vector<int> ans;
    int n = a1.size();

    // creating a map from array-a2
    unordered_map<int, pair<int, vector<int>>> m;

    for (int i = 0; i < n; i++) {
        // if the value already exists in the map
        if (m.find(a2[i]) != m.end()) {
            // pushing the index in the vector of the pair
            pair<int, vector<int>> &p = m[a1[i]];
            vector<int> &v = p.second;
            v.push_back(i);
        }

        // if not
        else {
            vector<int> v;
            v.push_back(i);
            pair<int, vector<int>> p;
            p.first = 0;
            p.second = v;
            m[a2[i]] = p;
        }
    }

    for (auto &[val, p] : m) {
        cout << val << " -> ";
        for (auto &value : p.second) {
            cout << value << " ";
        }
        cout << endl;
    }

    for (auto &val : a1) {
        auto &[key, value] = m[val];
        int subAns = value[key];
        ans.push_back(subAns);
        key++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a1;
    vector<int> a2;

    int val1, val2;
    for (int i = 0; i < n; i++) {
        cin >> val1;
        a1.push_back(val1);
    }
    for (int i = 0; i < n; i++) {
        cin >> val2;
        a2.push_back(val2);
    }

    vector<int> ans = anagramMapping(a1, a2);

    for (auto &val : ans) {
        cout << val << " ";
    }

    return 0;
}