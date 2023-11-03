
// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the permutations of the n coins (non-duplicate) using which the amount "amt" can be paid.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void coin_change_permutation_01(string asf, vector<int> coins, vector<int> &used, int tar)
{
    if (tar == 0)
    {
        cout << asf + "." << endl;

        return;
    }
    else if (tar < 0)
    {
        return;
    }

    for (int i = 0; i < coins.size(); i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            coin_change_permutation_01(asf + to_string(coins[i]) + "-", coins, used, tar - coins[i]);
            used[i] = 0;
        }
    }
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

    vector<int> used(n, 0);
    int tar;
    cin >> tar;

    coin_change_permutation_01("", coins, used, tar);
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

// OUPUT
// 2-3-7-.
// 2-7-3-.
// 3-2-7-.
// 3-7-2-.
// 5-7-.
// 7-2-3-.
// 7-3-2-.
// 7-5-.