#include <bits/stdc++.h>
using namespace std;

void print_permutations_02(int cb, int tb, int ssf, int ts, vector<int> items, string ans)
{

    if (cb > tb)
    {
        if (ssf == ts)
        {
            cout << ans << endl;
        }

        return;
    }

    for (int i = 0; i < ts; i++)
    {
        if (items[i] == 0)
        {
            items[i] = 1;
            print_permutations_02(cb + 1, tb, ssf + 1, ts, items, ans + to_string(i + 1));
            items[i] = 0;
        }
    }
    print_permutations_02(cb + 1, tb, ssf + 0, ts, items, ans + "0");
}

int main()
{

    int n;
    cin >> n;
    int r;
    cin >> r;

    vector<int> items(r, 0);

    print_permutations_02(1, n, 0, r, items, "");
    return 0;
}