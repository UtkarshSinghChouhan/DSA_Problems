#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int length(vector<int> &arr) {
    int len = 0, zCnt = 0, oCnt = 0, tCnt = 0, i = -1, n = arr.size();

    // "(oCnt - zCnt)#(tCnt - oCnt)" vs idx
    unordered_map<string, int> m;
    m.insert({"0#0", -1});

    while (i < n - 1) {
        i++;

        if (arr[i] == 0)
            zCnt++;
        if (arr[i] == 1)
            oCnt++;
        if (arr[i] == 2)
            tCnt++;

        int d10 = oCnt - zCnt;
        int d21 = tCnt - oCnt;

        string key = to_string(d10) + "#" + to_string(d21);

        if (m.count(key)) {
            int pLen = i - m[key];
            len = max(pLen, len);
        } else {
            m[key] = i;
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

// INPUT
// 13
// 1
// 1
// 2
// 0
// 1
// 0
// 1
// 2
// 1
// 2
// 2
// 0
// 1

// OUTPUT
// length = 9(longest subarray with equal no. of 0's, 1's and 2's)