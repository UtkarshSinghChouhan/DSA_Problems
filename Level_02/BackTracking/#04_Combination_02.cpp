

#include <bits/stdc++.h>
using namespace std;

void printCombinations02(vector<int> boxes, int ci, int ti, int lb)
{
    if (ci == ti + 1)
    {
        for (auto val : boxes)
        {
            if (val == 1)
            {
                cout << "i";
            }
            else
            {
                cout << "-";
            }
        }

        cout << endl;
        return;
    }

    for (int i = lb + 1; i < boxes.size(); i++)
    {
        boxes[i] = 1;
        printCombinations02(boxes, ci + 1, ti, i);
        }

    return;
}

int main()
{
    int n;
    cin >> n;
    int r;
    cin >> r;

    vector<int> boxes(n, 0);
    printCombinations02(boxes, 1, r, -1);
    return 0;
}