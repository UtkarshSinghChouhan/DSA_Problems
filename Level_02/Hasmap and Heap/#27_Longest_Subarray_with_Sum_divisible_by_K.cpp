#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int len(vector<int> &arr, int k) {
    int len = 0, i = -1, n = arr.size(), ssf = 0;

    unordered_map<int, int> m;
    m.insert({0, -1});

    while (i < n - 1) {
        i++;
        ssf += arr[i];

        int rem = ssf % k;
        if (rem < 0)
            rem += k;

        // if we have already encountered the remainder, then calculate the
        // length
        if (m.count(rem)) {
            int plen = i - m[rem];
            len = max(len, plen);
        } else {
            m[rem] = i;
        }
    }

    return len;
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

    int k;
    cin >> k;

    cout << len(arr, k);
    return 0;
}