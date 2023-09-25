// 1. You are given a graph and a src vertex.
// 2. You are required to find and print all hamiltonian paths and cycles starting from src. The cycles must end with "*" and paths with a "."

// Note -> A hamiltonian path is such which visits all vertices without visiting any twice. A hamiltonian path becomes a cycle if there is an edge between first and last vertex.
// Note -> Print in lexicographically increasing order.

// Input
// 7
// 9
// 0 1
// 1 2
// 2 3
// 0 3
// 3 4
// 4 5
// 5 6
// 4 6
// 2 5
// 0

// Output
// 0123456.
// 0123465.
// 0125643*
// 0346521*

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

bool isCycle(vector<vector<Edge>> graph, string psf)
{
    int originalSrc = psf[0] - '0';
    int lastVertex = psf[psf.length() - 1] - '0';

    for (Edge e : graph[lastVertex])
    {
        if (e.ngb == originalSrc)
        {
            return true;
        }
    }

    return false;
}

void traverseAndAdd(vector<vector<Edge>> graph, int src, vector<int> &visited, string psf)
{
    if (psf.length() == graph.size())
    {
        if (isCycle(graph, psf))
        {

            cout << psf << "*" << endl;
        }
        else
        {
            cout << psf << "." << endl;
        }

        return;
    }

    visited[src] = 1;
    for (Edge e : graph[src])
    {
        if (visited[e.ngb] == 0)
        {
            traverseAndAdd(graph, e.ngb, visited, psf + to_string(e.ngb));
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

    vector<int> visited(vtces, 0);

    traverseAndAdd(graph, src, visited, to_string(src));

    return 0;
}
