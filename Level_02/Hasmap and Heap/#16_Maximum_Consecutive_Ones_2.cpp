#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveOnes2(vector<int> &arr) {
    int n = arr.size();
    int ans = 0, zCnt = 0, i = -1, j = -1;

    while (true) {
        bool f1 = false, f2 = false;

        while (i < n - 1) {
            f1 = true;
            i++;
            if (arr[i] == 0)
                zCnt++;
            if (zCnt == 1) {
                int len = i - j;
                ans = max(len, ans);
            } else if (zCnt > 1)
                break;
        }

        while (j < i) {
            f2 = true;

            j++;

            if (arr[j] == 0)
                zCnt--;

            if (zCnt == 1)
                break;
        }

        if (f1 == false && f2 == false)
            break;
    }

    return ans;
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

    cout << maxConsecutiveOnes2(arr);
    return 0;
}

// INPUT
// 14
// 1
// 1
// 0
// 1
// 0
// 0
// 1
// 1
// 0
// 1
// 0
// 1
// 1
// 1

// OUTPUT
// 5