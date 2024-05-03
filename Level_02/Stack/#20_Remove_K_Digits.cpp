#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeKdigits(string &nums, int k)
{
    int i = 0;
    int len = nums.length();
    if (k == len)
    {
        return "0";
    }

    stack<char> st;


    while (k > 0 && i < len)
    {
        if (st.empty())
        {
            st.push(nums[i++]);
            continue;
        }

        if (st.top() > nums[i])
        {
            st.pop();
            k--;
        }

        st.push(nums[i++]);
    }

    // if the given string is monotonic increasing(strictly increasing)
    while (k > 0)
    {
        st.pop();
        k--;
    }

    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    // append the remaing chcracters of the string to the back
    while (i < len)
    {
        ans.push_back(nums[i++]);
    }

    // handle leading zeros
    int j = 0;
     while(j < ans.length()){
        if(ans[j] != '0') break;
        else j++;
     }

    return ans.substr(j);
}

int main()
{
    string str;
    cin >> str;

    int k; cin >> k;

    cout << removeKdigits(str, k);

    return 0;
}