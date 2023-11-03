// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the combinations of the n coins (same coin can be used
//      again any number of times) using which the amount "amt" can be paid.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void coin_change_02(int idx, vector<int> &coins, string asf, int tar)
{
    if (idx == coins.size())
    {
        if (tar == 0)
        {
            cout << asf + "." << endl;
        }

        return;
    }

    int iterationLimit = tar / coins[idx];
    for (int i = 1; i <= iterationLimit; i++)
    {
        string coinsCount = "";
        for (int j = 1; j <= i; j++)
        {
            coinsCount += to_string(coins[idx]) + "-";
        }
        coin_change_02(idx + 1, coins, asf + coinsCount, tar - (coins[idx] * i));
    }
    coin_change_02(idx + 1, coins, asf, tar - 0);
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int tar;
    cin >> tar;

    coin_change_02(0, coins, "", tar);

    return 0;
}

// INPUT
// 5
// 2
// 3
// 5
// 6
// 7
// 12

// OUTPUT
// 2-3-7-.
// 2-5-5-.
// 2-2-3-5-.
// 2-2-2-3-3-.
// 2-2-2-6-.
// 2-2-2-2-2-2-.
// 3-3-6-.
// 3-3-3-3-.
// 5-7-.
// 6-6-.
