#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> chess, int row, int col)
{

    // left horizontal
    for (int i = row, j = col; j >= 0; j--)
    {
        if (chess[i][j] != 0)
        {
            return false;
        }
    }

    // left diagonal upper
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] != 0)
        {
            return false;
        }
    }

    // vertically upwards
    for (int i = row, j = col; i >= 0; i--)
    {
        if (chess[i][j] != 0)
        {
            return false;
        }
    }

    // right diagonal upper
    for (int i = row, j = col; i >= 0 && j < chess.size(); i--, j++)
    {
        if (chess[i][j] != 0)
        {
            return false;
        }
    }

    // right horizontal
    for (int i = row, j = col; j < chess.size(); j++)
    {
        if (chess[i][j] != 0)
        {
            return false;
        }
    }

    // right diagonal lower
    for (int i = row, j = col; i < chess.size() && j < chess.size(); i++, j++)
    {
        if (chess[i][j] != 0)
        {
            return false;
        }
    }

    // vertically downwards
    for (int i = row, j = col; i < chess.size(); i++)
    {
        if (chess[i][j] != 0)
        {
            return false;
        }
    }

    // left diagonal lower
    for (int i = row, j = col; i < chess.size() && j >= 0; i++, j--)
    {
        if (chess[i][j] != 0)
        {
            return false;
        }
    }

    return true;
}

void n_queen_permutations(int qpsf, int tq, vector<vector<int>> chess)
{

    if (qpsf == tq)
    {
        for (int i = 0; i < chess.size(); i++)
        {
            for (int j = 0; j < chess.size(); j++)
            {
                if (chess[i][j] == 0)
                {
                    cout << chess[i][j] << " ";
                }
                else
                {
                    cout << "q" << chess[i][j] << " ";
                }
            }

            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < chess.size() * chess.size(); i++)
    {
        int row = i / chess.size();
        int col = i % chess.size();

        if (chess[row][col] == 0 && isSafe(chess, row, col))
        {
            chess[row][col] = qpsf + 1;

            n_queen_permutations(qpsf + 1, tq, chess);

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

    n_queen_permutations(0, n, chess);

    return 0;
}
