#include <iostream>
#include <limits.h>
#include <unordered_set>
#include <vector>
using namespace std;

bool check(vector<int> &arr) {
    int minVal = INT_MAX, maxVal = INT_MIN;
    unordered_set<int> s;

    for (auto &val : arr) {
        minVal = min(minVal, val);
        maxVal = max(maxVal, val);
        s.insert(val);
    }

    int d = maxVal - minVal;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int ele = minVal + i * d;
        if (!s.count(ele)) {
            return false;
        }
    }
    return true;
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

    cout << check(arr);

    return 0;
}