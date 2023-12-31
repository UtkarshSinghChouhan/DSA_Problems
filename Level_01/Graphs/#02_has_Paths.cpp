#include <bits/stdc++.h>
using namespace std;

// Weighted Graph
class Edge
{
public:
    int src;
    int ngb;

    Edge(int src, int ngb)
    {
        this->src = src;
        this->ngb = ngb;
    }
};

bool hasPath(vector<vector<Edge>> graph, int src, int des, vector<int> visited)
{
    if (src == des)
    {
        return true;
    }

    visited[src] = 1;

    for (Edge e : graph[src])
    {
        if (visited[e.ngb] == 0)
        {

            bool ngbAns = hasPath(graph, e.ngb, des, visited);
            if (ngbAns == true)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int vtces;
    cin >> vtces;
    int edges;
    cin >> edges;

    // Adjacency List
    vector<vector<Edge>> graph(vtces);

    // Taking the input of the weighted graph
    for (int i = 0; i < edges; i++)
    {
        int src, ngb;
        cin >> src >> ngb;

        graph[src].push_back(Edge(src, ngb));
        graph[ngb].push_back(Edge(ngb, src));
    }

    int src;
    cin >> src;
    int des;
    cin >> des;

    vector<int> visited(vtces, 0);

    if (hasPath(graph, src, des, visited))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }

    return 0;
}

// 1. You are given a graph, a src vertex and a destination vertex.
// 2. You are required to find if a path exists between src and dest. If it does, print true
//      otherwise print false.

// Input
// 7
// 8
// 0 1
// 1 2
// 2 3
// 0 3
// 3 4
// 4 5
// 5 6
// 4 6
// 0
// 6

// Output
// TRUE