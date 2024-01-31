#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countSubarrayK(vector<int> &arr, int k) {
    int cnt = 0, ssf = 0, i = -1, n = arr.size();

    unordered_map<int, int> m;
    m.insert({0, 1});

    while (i < n - 1) {
        i++;
        ssf += arr[i];

        if (m.count(ssf - k)) {
            cnt += m[ssf - k];
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

    int k;
    cin >> k;

    cout << countSubarrayK(arr, k);
    return 0;
}