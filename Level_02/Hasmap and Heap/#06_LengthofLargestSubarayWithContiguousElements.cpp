#include <iostream>
#include <limits.h>
#include <set>
#include <vector>

using namespace std;

int maxLen(vector<int> &arr) {
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n - 1; i++) {
        int minN = arr[i];
        int maxN = arr[i];
        set<int> s;
        s.insert(arr[i]);
        for (int j = i + 1; j < n; j++) {
            if (s.find(arr[j]) == s.end()) {
                s.insert(arr[j]);

                minN = min(minN, arr[j]);
                maxN = max(maxN, arr[j]);

                if (maxN - minN == j - i) {
                    len = max(len, (j - i) + 1);
                }
            }
        }
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    int val;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        arr.push_back(val);
    }

    cout << maxLen(arr);
    return 0;
}