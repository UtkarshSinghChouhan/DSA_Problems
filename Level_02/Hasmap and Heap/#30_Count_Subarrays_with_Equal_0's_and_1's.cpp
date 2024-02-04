#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int count(vector<int> &arr) {
    int cnt = 0, ssf = 0, i = -1, n = arr.size();

    // sum-so-far vs frequency
    unordered_map<int, int> m;
    m.insert({0, 1});

    while (i < n - 1) {
        i++;
        ssf += (arr[i] == 0) ? -1 : 1;

        if (m.count(ssf)) {
            cnt += m[ssf];
        }
        m[ssf]++;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cout << count(arr);
    return 0;
}

// INPUT
// 13
// 0
// 0
// 1
// 0
// 1
// 0
// 1
// 1
// 0
// 0
// 1
// 1
// 1

// INPUT
// count = 24