// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the permutations in which n queens can be placed on the
//      n * n chess-board.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void queen_permutation_02(int i, int j, int cq, int tq, vector<int> &queens, string asf)
{
    if (i == tq)
    {
        if (cq == tq)
        {
            cout << asf << endl;
        }
        return;
    }

    int nR = i, nC = j;
    string sep = "";

    if (j == tq - 1)
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

    for (int i = 0; i < queens.size(); i++)
    {
        if (queens[i] == 0)
        {
            queens[i] = 1;
            queen_permutation_02(nR, nC, cq + 1, tq, queens, asf + "q" + to_string(i + 1) + sep);
            queens[i] = 0;
        }
    }
    queen_permutation_02(nR, nC, cq + 0, tq, queens, asf + "-" + sep);

    return;
}

int main()
{

    int n;
    cin >> n;
    vector<int> queens(n, 0);
    queen_permutation_02(0, 0, 0, n, queens, "");

    return 0;
}