#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int multiSourceBFS(vector<vector<int>> &routes, int src, int tar)
{

    // Stop - vs - Buses
    map<int, vector<int>> m;

    int len = routes.size();

    for (int bus = 0; bus < len; bus++)
    {

        for (auto &stop : routes[bus])
        {

            m[stop].push_back(bus);
        }
    }

    queue<int> q;

    set<int> visStops;
    visStops.insert(src);

    set<int> visBuses;

    for (auto &bus : m[src])
    {
        q.push(bus);
    }

    int lvl = 1;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            // remove
            int bus = q.front();
            q.pop();

            // mark bus visited
            visBuses.insert(bus);

            for (auto &stop : routes[bus])
            {

                if (visStops.find(stop) == visStops.end())
                {

                    if (stop == tar)
                    {
                        return lvl;
                    }

                    for (auto &bus : m[stop])
                    {

                        // add unvisited buses to the queue
                        if (visBuses.find(bus) == visBuses.end())
                        {
                            q.push(bus);
                        }
                    }

                    // mark Stop visited
                    visStops.insert(stop);
                }
            }
        }
        lvl++;
    }

    return -1;
}

int main()
{
    // Taking input
    int n, m;
    cin >> n >> m;

    vector<vector<int>> routes(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> routes[i][j];
        }
    }

    int src, tar;
    cin >> src >> tar;

    if (src == tar)
    {
        cout << "0" << endl;
        return 0;
    }

    cout << multiSourceBFS(routes, src, tar);

    return 0;
}