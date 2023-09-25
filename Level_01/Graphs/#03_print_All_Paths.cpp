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

void printAllPaths(vector<vector<Edge>> graph, int src, int des, vector<int> visited, string psf)
{
    if (src == des)
    {
        cout << psf << endl;
        return;
    }

    visited[src] = 1;

    for (Edge e : graph[src])
    {
        if (visited[e.ngb] == 0)
        {

            printAllPaths(graph, e.ngb, des, visited, psf + to_string(e.ngb));
        }
    }

    visited[src] = 0;

    return;
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

    printAllPaths(graph, src, des, visited, "0");

    return 0;
}

// 1. You are given a graph, a source vertex and a destination vertex.
// 2. You are required to find and print all paths between source and destination. Print
//      them in lexicographical order.

//     E.g. Check the following paths
//              012546
//              01256
//              032546
//              03256

//     The lexicographically smaller path is printed first.

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
// 0123456
// 012346
// 03456
// 0346