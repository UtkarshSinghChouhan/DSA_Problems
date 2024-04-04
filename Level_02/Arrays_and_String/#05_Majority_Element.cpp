#include <iostream>
#include <vector>
#include <map>
using namespace std;

// BRUTE FORCE - 0
int solution_00(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int freq = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                freq++;
            }
        }

        if (freq >= n / 2 + 1)
        {
            return arr[i];
        }
    }

    return -1;
}

// BRUTE FORCE - 1
int solution_01(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> m;
    for (auto &val : arr)
    {
        m[val]++;
        if (m[val] >= n / 2 + 1)
        {
            return val;
        }
    }

    return -1;
}

// OPTIMIZED - [MOORE'S VOOTING ALGORITHM] === Neetcode Solution
int solution_02(vector<int> &arr){
    int res = 0, count = 0;
    for(auto & val : arr){
        if(count == 0) res = val;
        count += (res == val) ? 1 : -1;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cout << solution_02(arr);

    return 0;
}
