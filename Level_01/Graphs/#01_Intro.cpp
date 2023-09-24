#include <bits/stdc++.h>
using namespace std;

// Weighted Graph
class Edge
{
public:
    int src;
    int ngb;
    int wt;

    Edge(int src, int ngb, int wt)
    {
        this->src = src;
        this->ngb = ngb;
        this->wt = wt;
    }
};

int main()
{
    int vtces, edges;
    cin >> vtces, edges;

    // Adjacency List
    vector<vector<Edge>> graph(vtces);

    // Taking the input of the weighted graph
    for (int i = 0; i < edges; i++)
    {
        int src, ngb, wt;
        cin >> src >> ngb >> wt;

        graph[src].push_back(Edge(src, ngb, wt));
        graph[ngb].push_back(Edge(ngb, src, wt));
    }

    return 0;
}

// Input
// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10