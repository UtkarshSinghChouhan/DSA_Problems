// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the permutations of the n coins (same coin can be used again any number of times) using which the amount "amt" can be paid.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void coin_change_permutation_02(string asf, vector<int> &coins, int tar)
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
        coin_change_permutation_02(asf + to_string(coins[i]) + "-", coins, tar - coins[i]);
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
    int tar;
    cin >> tar;

    coin_change_permutation_02("", coins, tar);

    return 0;
}

// INPUT
// 3
// 2
// 3
// 5
// 7

// OUTPUT
// 2-2-3-.
// 2-3-2-.
// 2-5-.
// 3-2-2-.
// 5-2-.