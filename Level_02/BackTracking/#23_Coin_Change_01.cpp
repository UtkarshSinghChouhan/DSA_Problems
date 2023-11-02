// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the combinations of the n coins (non-duplicate) using
//      which the amount "amt" can be paid.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void coin_change_01(int idx, vector<int> arr, string asf, int tar)
{
    if (idx == arr.size())
    {
        if (tar == 0)
        {
            cout << asf + "." << endl;
        }
        return;
    }

    coin_change_01(idx + 1, arr, asf, tar - 0);
    coin_change_01(idx + 1, arr, asf + "-" + to_string(arr[idx]), tar - arr[idx]);

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tar;
    cin >> tar;

    // for (auto &val : arr)
    // {
    //     cout << val << " ";
    // }

    coin_change_01(0, arr, "", tar);
    return 0;
}

// INPUT

// OUTPUT
