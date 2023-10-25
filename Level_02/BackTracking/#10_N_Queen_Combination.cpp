
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> chess, int row, int col)
{
    // left horizontal

    for (int i = row, j = col; j >= 0; j--)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    // vertically upwards
    for (int i = row, j = col; i >= 0; i--)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    // left diagonal upwards

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    // right diagonal upwards

    for (int i = row, j = col; i >= 0 && j < chess.size(); i--, j++)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void n_queen_combintions(vector<vector<int>> chess, int qpsf, int tq, int lc)
{

    if (qpsf == tq)
    {
        for (int i = 0; i < tq; i++)
        {
            for (int j = 0; j < tq; j++)
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

    for (int i = lc + 1; i < tq * tq; i++)
    {
        int row = i / tq;
        int col = i % tq;

        if (isSafe(chess, row, col))
        {
            chess[row][col] = 1;
            n_queen_combintions(chess, qpsf + 1, tq, i);
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

    n_queen_combintions(chess, 0, n, -1);

    return 0;
}
