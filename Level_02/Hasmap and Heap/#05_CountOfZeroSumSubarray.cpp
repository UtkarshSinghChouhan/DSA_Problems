#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findSubarray(vector<int> &arr) {
    int n = arr.size();
    int cnt = 0, ssf = 0;

    // SUM vs FREQUENCY
    unordered_map<int, int> m;
    m.insert({0, 1});

    for (int i = 0; i < n; i++) {
        ssf += arr[i];

        if (m.count(ssf)) {
            cnt += m[ssf];
            m[ssf] += 1;
        } else {
            m[ssf]++;
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findSubarray(arr);

    return 0;
}

// INPUT
// 12
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
// 6
