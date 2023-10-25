// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the permutations in which n queens can be placed on the
//      n * n chess-board.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void queen_permutation_01(vector<vector<int>> &chess, int cq, int tq)
{
    // Base Smart
    if (cq > tq)
    {
        for (int i = 0; i < chess.size(); i++)
        {
            for (int j = 0; j < chess.size(); j++)
            {
                if (chess[i][j] != 0)
                {
                    cout << "q" << chess[i][j];
                }
                else
                {
                    cout << "-";
                }
            }
            cout << endl;
        }
        cout << endl;

        return;
    }

    // call dumb
    for (int i = 0; i < chess.size(); i++)
    {
        for (int j = 0; j < chess.size(); j++)
        {
            if (chess[i][j] == 0)
            {
                chess[i][j] = cq;
                queen_permutation_01(chess, cq + 1, tq);
                chess[i][j] = 0;
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> chess(n, vector<int>(n, 0));

    queen_permutation_01(chess, 1, n);
    return 0;
}

// INPUT
// 2

// OUTPUT
// q1q2
// --

// q1-
// q2-

// q1-
// -q2

// q2q1
// --

// -q1
// q2-

// -q1
// -q2

// q2-
// q1-

// -q2
// q1-

// --
// q1q2

// q2-
// -q1

// -q2
// -q1

// --
// q2q1