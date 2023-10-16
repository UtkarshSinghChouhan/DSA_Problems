// #include <bits/stdc++.h>

// using namespace std;

// int minOperations(vector<int> &nums, int k)
// {

//     set<int> s;
//     for (int i = 1; i <= k; i++)
//     {
//         s.insert(i);
//     }

//     int i = nums.size() - 1;

//     int count = 0;

//     while (i >= 0 && !s.empty())
//     {
//         if (s.find(nums[i]) != s.end())
//         {
//             s.erase(nums[i]);
//         }
//         count++;
//         i--;
//     }

//     return count;
// }

// int main()
// {

//     int size;
//     cin >> size;

//     vector<int> nums(size);

//     for (int i = 0; i < size; i++)
//     {
//         int val;
//         cin >> val;
//         nums.push_back(val);
//     }

//     int k;
//     cin >> k;

//     cout << minOperations(nums, k);
//     return 0;
// }

// [3,1,5,4,2]
// 2
// [3,1,5,4,2]
// 5
// [3,2,5,3,1]
// 3

// [14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12]