#include <bits/stdc++.h>
using namespace std;

void queenCombination_02(vector<vector<int>> chess, int qpsf, int lp)
{

    if (qpsf == chess.size())
    {
        for (int i = 0; i < chess.size(); i++)
        {
            for (int j = 0; j < chess.size(); j++)
            {
                if (chess[i][j] == 1)
                {
                    cout << "q";
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

    int n = chess.size();
    for (int i = lp + 1; i < n * n; i++)
    {
        int r = i / n;
        int c = i % n;

        chess[r][c] = 1;
        queenCombination_02(chess, qpsf + 1, i);
        chess[r][c] = 0;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n, 0));

    queenCombination_02(chess, 0, -1);

    return 0;
}