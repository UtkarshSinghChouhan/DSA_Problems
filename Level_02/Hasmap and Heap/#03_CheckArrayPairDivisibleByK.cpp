#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool check(vector<int> &arr, int k) {
    unordered_map<int, int> m;

    for (auto &val : arr)
        m[val]++;

    for (auto &val : arr) {
        int rem = val % k;

        if (rem == 0) {
            if (m[rem] % 2 != 0)
                return false;
        } else if (2 * rem == k) {
            if (m[rem] % 2 != 0)
                return false;
        } else {
            if (m[rem] != m[k - rem])
                return false;
        }
    }

    return true;
}

int main() {
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> arr(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << check(arr, k);
}

// INPUT
// 10   //k
// 12   //n
// 77
// 22
// 56
// 11
// 45
// 20
// 34
// 78
// 29
// 33
// 55
// 30
// 40

// OUTPUT
// 1