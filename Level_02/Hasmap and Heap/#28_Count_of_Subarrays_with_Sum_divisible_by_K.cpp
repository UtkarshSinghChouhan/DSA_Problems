#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int count(vector<int> &arr, int k) {
    int cnt = 0, ssf = 0, i = -1, n = arr.size();

    // remainder vs frequency
    unordered_map<int, int> m;
    m.insert({0, 1});

    while (i < n - 1) {
        i++;
        ssf += arr[i];

        int rem = ssf % k;

        if (rem < 0)
            rem += k;

        if (m.count(rem)) {
            cnt += m[rem];
        }

        m[rem]++;
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

    int k;
    cin >> k;

    cout << count(arr, k);

    return 0;
}
