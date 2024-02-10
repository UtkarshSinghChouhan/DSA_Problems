#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int count(vector<vector<int>> &A, vector<vector<int>> &B, int tar) {
    unordered_set<int> s;
    int cnt = 0;

    for (auto &v : A) {
        for (auto &val : v) {
            s.insert(val);
        }
    }

    for (auto &v : B) {
        for (auto &val : v) {
            int comp = tar - val;

            if (s.count(comp))
                cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> A;
    vector<vector<int>> B;

    vector<int> arr;
    int val;
    for (int i = 0; i < n; i++) {
        arr = {};
        for (int j = 0; j < n; j++) {
            cin >> val;
            arr.push_back(val);
        }
        A.push_back(arr);
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        arr = {};
        for (int j = 0; j < n; j++) {
            cin >> val;
            arr.push_back(val);
        }
        B.push_back(arr);
        cout << endl;
    }

    int tar;
    cin >> tar;

    cout << count(A, B, tar);

    return 0;
}

// INPUT
// 3
// 1 5 6
// 8 10 11
// 15 16 18
// 2 4 7
// 9 10 12
// 13 16 20
// 21

// OUTPUT
// count = 4