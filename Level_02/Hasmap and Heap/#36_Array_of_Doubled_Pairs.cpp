#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void removeFromMap(unordered_map<int, int> &m, int key) {
    if (m[key] == 1)
        m.erase(key);
    else
        m[key]--;
}

int check(vector<int> &arr) {
    unordered_map<int, int> m;

    for (auto &val : arr) {
        m[val]++;
    }

    for (auto &val : arr) {

        if (m.count(val)) {

            int limit = m[val];
            for (int i = 0; i < limit; i++) {

                if (!m.count(2 * val)) {
                    break;
                }
                removeFromMap(m, 2 * val);
                removeFromMap(m, val);
            }
        }
    }

    int n = m.size();
    if (n != 0) {
        cout << "not vacant ";
        return 0;
    } else {
        cout << "vacant ";
        return 1;
    }
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

// INPUT
// 16
// -8
// -3
// 8
// 8
// 4
// -6
// -4
// 2
// 0
// 2
// 1
// 4
// 0
// 16
// 8
// 4

// OUTPUT
// 1(Yes it can be reordered)