// 1. You are given a number n.
// 2. You are required to print the nth element of fibonnaci sequence.

// Note -> Notice precisely how we have defined the fibonnaci sequence
// 0th element -> 0
// 1st element -> 1
// 2nd element -> 1
// 3rd element -> 2
// 4th element -> 3
// 5th element -> 5
// 6th element -> 8

// INPUT n = 10;
// OUTPUT fibonacci of n = 55

#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int nm1 = fib(n - 1);
    int nm2 = fib(n - 2);
    int fn = nm1 + nm2;

    return fn;
}

// Memoized Method
int fibMemo(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        cout << "Enterred value for" << n << endl;
        return dp[n];
    }

    int nm1 = fibMemo(n - 1, dp);
    int nm2 = fibMemo(n - 2, dp);

    int fn = nm1 + nm2;

    dp[n] = fn;

    return fn;
}

int main()
{
    int n;
    cin >> n;
    // cout << fib(n);

    // memoization
    vector<int> dp(n + 1, -1);
    cout << fibMemo(n, dp);
    return 0;
}