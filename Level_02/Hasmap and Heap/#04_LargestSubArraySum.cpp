#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxLen(vector<int> &arr) {
    int len = 0, ssf = 0, n = arr.size();

    // SUM vs INDEX
    unordered_map<int, int> m;
    m.insert({0, -1});

    for (int i = 0; i < n; i++) {
        ssf += arr[i];

        // if already exists in the map
        if (m.count(ssf)) {
            len = max(len, (i - m[ssf]));
        }
        // if it is not in the map
        else {
            m[ssf] = i;
        }
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxLen(arr);
    return 0;
}

// INPUT
// 12
// 0
// 8
// -3
// -5
// 2
// -4
// 6
// 1
// 2
// 1
// -3
// 4

// OUTPUT
// 8