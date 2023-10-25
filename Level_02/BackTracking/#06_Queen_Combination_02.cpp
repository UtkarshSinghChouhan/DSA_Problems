// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the combinations in which n queens can be placed on the
//      n * n chess-board.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void queenCombination_01(int i, int j, int ci, int ti, string asf)
{
    if (i == ti)
    {
        if (ci == ti)
        {
            cout << asf << endl;
        }

        return;
    }

    int nR = i, nC = j;
    string sep = "";

    if (j == ti - 1)
    {
        nR = i + 1;
        nC = 0;
        sep = "\n";
    }
    else
    {
        nR = i;
        nC = j + 1;
        sep = "";
    }

    queenCombination_01(nR, nC, ci + 1, ti, asf + 'q' + sep);
    queenCombination_01(nR, nC, ci, ti, asf + '-' + sep);

    return;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> chessBoard(n, vector<int>(n, 0));

    queenCombination_01(0, 0, 0, n, "");

    return 0;
}