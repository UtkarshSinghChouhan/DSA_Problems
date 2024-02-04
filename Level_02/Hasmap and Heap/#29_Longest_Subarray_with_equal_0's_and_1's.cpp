#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int length(vector<int> &arr) {
    int len = 0, ssf = 0, i = -1, n = arr.size();

    // sum-so-far vs index
    unordered_map<int, int> m;
    m.insert({0, -1});

    while (i < n - 1) {
        i++;
        ssf += arr[i] == 0 ? -1 : 1;

        if (m.count(ssf)) {
            int pLen = i - m[ssf];
            len = max(pLen, len);
        } else {
            m[ssf] = i;
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

    cout << length(arr);

    return 0;
}