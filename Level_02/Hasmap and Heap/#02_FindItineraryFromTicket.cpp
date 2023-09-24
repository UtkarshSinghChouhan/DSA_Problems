#include <bits/stdc++.h>
using namespace std;

void printPath(map<string, string> m, string root)
{
    cout << root << "->";
    printPath(m, m[root]);
}

int main()
{
    int n;
    cin >> n;
    map<string, string> m;
    map<string, bool> findRoot;

    for (int i = 0; i < n; i++)
    {
        string src, des;
        cin >> src >> des;

        m[src] = des;

        if (m.find(src) == m.end())
        {
            findRoot[src] = false;
        }

        findRoot[des] = false;
    }

    string root = "";
    for (auto it : findRoot)
    {
        // if(findRoot[it.first] == true){
        //     root = it.first;
        // }

        cout << it.first << "->" << it.second << endl;
    }

    cout << root << endl;

    // printPath(m, root);

    return 0;
}