#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> twoSum(vector<int> &arr, int tar, int si, int ei) {
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    while (si < ei) {
        int sum = arr[si] + arr[ei];

        if (sum < tar) {
            si++;
        } else if (sum > tar) {
            ei--;
        } else {
            ans.push_back({arr[si], arr[ei]});
            si++;
            ei--;
            while (si < ei && arr[si - 1] == arr[si])
                si++;
            while (si < ei && arr[ei] == arr[ei + 1])
                ei--;
        }
    }

    return ans;
}

vector<vector<int>> threeSum(vector<int> &arr, int tar, int si, int ei) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = si; i <= ei; i++) {
        if (i != si && arr[i - 1] == arr[i])
            continue;
        vector<vector<int>> arrPair = twoSum(arr, tar - arr[i], i + 1, ei);

        for (auto &v : arrPair) {
            v.push_back(arr[i]);
            ans.push_back(v);
        }
    }

    return ans;
}

vector<vector<int>> fourSum(vector<int> &arr, int tar, int si, int ei) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = si; i <= ei; i++) {
        if (i != si && arr[i - 1] == arr[i])
            continue;
        vector<vector<int>> arrPair = threeSum(arr, tar - arr[i], i + 1, ei);

        for (auto &v : arrPair) {
            v.push_back(arr[i]);
            ans.push_back(v);
        }
    }

    return ans;
}

vector<vector<int>> fourSumMethod2(vector<int> &arr, int tar) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++) {

            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;

            int si = j + 1, ei = n - 1;

            while (si < ei) {
                int sum = arr[i] + arr[j] + arr[si] + arr[ei];

                if (sum > tar) {
                    ei--;
                } else if (sum < tar) {
                    si++;
                } else {
                    ans.push_back({arr[i], arr[j], arr[si], arr[ei]});
                    si++;
                    ei--;

                    while (si < ei && arr[si] == arr[si - 1])
                        si++;
                    while (si < ei && arr[ei] == arr[ei + 1])
                        ei--;
                }
            }
        }
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

    int tar;
    cin >> tar;

    // vector<vector<int>> ans = twoSum(arr, tar, 0, n - 1);
    // vector<vector<int>> ans = threeSum(arr, tar, 0, n - 1);
    // vector<vector<int>> ans = fourSum(arr, tar, 0, n - 1);
    vector<vector<int>> ans = fourSumMethod2(arr, tar);

    // display
    cout << "[";
    for (auto &v : ans) {
        cout << "[";
        for (auto &val : v) {
            cout << val << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0;
}

// INPUT
// 21
// 4
// 2
// 8
// 7
// 2
// 3
// 10
// 2
// 4
// 3
// 2
// 10
// 10
// 4
// 5
// 5
// 7
// 5
// 2
// 4
// 4
// tar = 7 // twoSum
// tar = 17 // threeSum
// tar = 17 // fourSum

// OUTPUT

// TWOSUM
// [[2, 5, ], [3, 4, ], ]

// THREESUM
// [[5, 10, 2, ], [7, 8, 2, ], [4, 10, 3, ], [7, 7, 3, ], [5, 8, 4, ], [5, 7, 5,
// ], ]

// FOURSUM
// [[2, 2, 3, 10, ], [2, 2, 5, 8, ], [2, 3, 4, 8, ], [2, 3, 5, 7, ], [2, 4, 4,
// 7, ], [2, 5, 5, 5, ], [3, 3, 4, 7, ], [3, 4, 5, 5, ], [4, 4, 4, 5, ], ]