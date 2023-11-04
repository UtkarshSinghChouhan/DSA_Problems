// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".
// 4. You are required to calculate and print true or false, if there is a subset the elements of which add
//      up to "tar" or not.

#include <bits/stdc++.h>
using namespace std;

bool target_subset_sum(string asf, int idx, vector<int> nums, int tar)
{
    if (idx == nums.size())
    {
        if (tar == 0)
        {
            cout << asf << endl;
            return true;
        }
        return false;
    }
    bool ans1 = target_subset_sum(asf, idx + 1, nums, tar - 0);
    if (ans1)
    {
        return true;
    }
    bool ans2 = target_subset_sum(asf + to_string(nums[idx]) + "-", idx + 1, nums, tar - nums[idx]);
    if (ans2)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int tar;
    cin >> tar;

    bool ans = target_subset_sum("", 0, nums, tar);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}

// CONSTRAINTS
// 1 <= n <= 30
// 0 <= n1, n2, .. n elements <= 20
// 0 <= tar <= 50

// INPUT
// 5
// 4
// 2
// 7
// 1
// 3
// 10

// OUTPUT
// true