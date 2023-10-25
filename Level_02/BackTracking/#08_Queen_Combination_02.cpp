// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the combinations in which n queens can be placed on the
//      n * n chess-board.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void queenCombination_02(vector<vector<int>> chess, int i, int j, int qpsf)
{
    if (qpsf == chess.size())
    {
        for (int row = 0; row < chess.size(); row++)
        {
            for (int col = 0; col < chess.size(); col++)
            {
                cout << chess[row][col];
            }

            cout << endl;
        }

        cout << endl;
        return;
    }

    for (int col = j + 1; col < chess.size(); col++)
    {
        chess[i][col] = 1;
        queenCombination_02(chess, i, col, qpsf + 1);
        chess[i][col] = 0;
    }

    for (int row = i + 1; row < chess.size(); row++)
    {
        for (int col = 0; col < chess.size(); col++)
        {
            chess[row][col] = 1;
            queenCombination_02(chess, row, col, qpsf + 1);
            chess[row][col] = 0;
        }
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> chess(n, vector<int>(n, 0));

    queenCombination_02(chess, 0, -1, 0);

    return 0;
}