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

void makeTree(vector<vector<Edge>> graph, int src, vector<int> &visited, vector<int> &comp)
{
    visited[src] = 1;
    comp.push_back(src);

    for (Edge e : graph[src])
    {
        if (visited[e.ngb] == 0)
        {
            makeTree(graph, e.ngb, visited, comp);
        }
    }

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

    vector<int> visited(vtces, 0);

    vector<vector<int>> connected_comp;

    for (int i = 0; i < vtces; i++)
    {
        vector<int> comp;
        if (visited[i] == 0)
        {
            makeTree(graph, i, visited, comp);
            connected_comp.push_back(comp);
        }
    }

    // printing the output
    cout << "[";
    for (auto comp : connected_comp)
    {
        cout << "[";
        for (auto val : comp)
        {
            cout << val << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;

    return 0;
}

// 1. You are given a graph.
// 2. You are required to find and print all connected components of the graph.

// Input
// 7
// 5
// 0 1
// 2 3
// 4 5
// 5 6
// 4 6

// Output
// [[0, 1], [2, 3], [4, 5, 6]]