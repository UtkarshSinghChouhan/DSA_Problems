#include <iostream>
#include <vector>
using namespace std;

// Brute-Force
vector<int> transform(vector<int> &ans, vector<vector<int>> queries)
{
    for(auto &query : queries){
        for(int i = query[0]; i <= query[1]; i++){
            ans[i] += query[2];
        }
    }

    return ans;
}

// Optimized Presum Sum Approach
vector<int> transformOptimized(vector<int> &ans, vector<vector<int>> queries){
    int size = ans.size();
    // Impact Step
    for(auto &query : queries){
        int startIdx = query[0];
        int endIdx = query[1];
        int val = query[2];


        ans[startIdx] = val;
        if(endIdx + 1 < size){
            ans[endIdx + 1] = -val;
        }
    }

    // Calculating the prefix sum and updating the answer array
    int ssf = 0;
    for(int i = 0; i < size; i++){
        ssf += ans[i];
        ans[i] = ssf;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n, 0);

    int m;
    cin >> m;
    vector<vector<int>> queries;

    for (int i = 1; i <= m; i++)
    {
        int startIdx, endIdx, val;
        cin >> startIdx >> endIdx >> val;
        queries.push_back({startIdx, endIdx, val});
    }

    vector<int> res1 = transform(ans, queries);
    vector<int> res = transformOptimized(ans, queries);
    for (auto &val : res)
    {
        cout << val << " ";
    }

    return 0;
}