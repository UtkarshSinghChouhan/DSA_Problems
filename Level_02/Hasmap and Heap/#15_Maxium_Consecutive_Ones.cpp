#include <iostream>
#include <vector>

using namespace std;

int maxConsecutiveOnes1(vector<int> &arr, int k) {
    int n = arr.size();
    int ans = 0, zCnt = 0, i = -1, j = -1;

    while (true) {
        bool f1 = false, f2 = false;

        while (i < n - 1) {
            f1 = true;
            i++;
            if (arr[i] == 0)
                zCnt++;

            if (zCnt <= k) {
                int len = i - j;
                ans = max(ans, len);
            } else if (zCnt > k) {
                break;
            }
        }

        while (j < i) {
            f2 = true;
            j++;
            if (arr[j] == 0)
                zCnt--;

            if (zCnt == k)
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

    cout << maxConsecutiveOnes1(arr, k);
    return 0;
}

// INPUT-1
// n=13
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
// k=2

// OUTPUT-1
//  ans = 7

// INPUT-2
// n=6
// 1
// 1
// 0
// 0
// 1
// 1
// 1
// k=1

// OUTPUT-2
//  ans = 3