#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void removeFromMap(unordered_map<int, int> &m, int n) {
    if (m[n] == 1)
        m.erase(n);
    else
        m[n]--;
}

int findK(vector<int> &arr) {
    unordered_set<int> s;
    for (auto &val : arr)
        s.insert(val);
    return s.size();
}

int countEquivalentSubarray(vector<int> &arr) {
    int k = findK(arr);
    int n = arr.size();
    int cnt = 0, i = -1, j = -1;

    unordered_map<int, int> m;

    while (true) {
        bool f1 = false, f2 = false;

        // acquiring
        while (i < n - 1) {
            f1 = true;
            i++;
            m[arr[i]]++;

            if (m.size() == k) {
                break;
            }
        }

        // releasing
        while (j < i) {
            f2 = true;
            if (m.size() == k) {
                cnt += n - i;
            }

            j++;
            removeFromMap(m, arr[j]);
            if (m.size() < k)
                break;
        }

        if (f1 == false && f2 == false)
            break;
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

    cout << countEquivalentSubarray(arr);

    return 0;
}

// INPUT
// n=10
// 2
// 5
// 3
// 5
// 2
// 4
// 1
// 3
// 1
// 4

// OUTPUT
// 15
