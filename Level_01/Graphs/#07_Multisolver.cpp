// 1. You are given a graph, a src vertex and a destination vertex.
// 2. You are give a number named "criteria" and a number "k".
// 3. You are required to find and print the values of
// 3.1 Smallest path and it's weight separated by an "@"
// 3.2 Largest path and it's weight separated by an "@"
// 3.3 Just Larger path (than criteria in terms of weight) and it's weight separated by an "@"
// 3.4 Just smaller path (than criteria in terms of weight) and it's weight separated by an "@"
// 3.5 Kth largest path and it's weight separated by an "@"

// Input
// 7
// 9
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8
// 2 5 5
// 0
// 6
// 30
// 4

// Smallest Path01256@28
// Largest Path032546@66
// CEIL (Just larger path) that 30 = 012546@36
// FLOOR (Just Smaller path) that 30 = 01256@28
// 4th largest path = 03456@48

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

string spath = "";
int spathWt = INT_MAX;

string lpath = "";
int lpathWt = INT_MIN;

string cpath = "";
int cpathWt = INT_MAX;

string fpath = "";
int fpathWt = INT_MIN;

void traverse(vector<vector<Edge>> graph, int src, int des, int criteria, vector<int> &visited, string psf, int wsf)
{
    if (src == des)
    {

        if (wsf < spathWt)
        {
            spath = psf;
            spathWt = wsf;
        }

        if (wsf > lpathWt)
        {
            lpath = psf;
            lpathWt = wsf;
        }

        if (wsf > criteria && wsf < cpathWt)
        {
            cpath = psf;
            cpathWt = wsf;
        }

        if (wsf < criteria && wsf > fpathWt)
        {
            fpath = psf;
            fpathWt = wsf;
        }
    }

    visited[src] = 1;

    for (Edge e : graph[src])
    {
        if (visited[e.ngb] == 0)
        {
            traverse(graph, e.ngb, des, criteria, visited, psf + to_string(e.ngb), wsf + e.wt);
        }
    }

    visited[src] = 0;
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
        int src, ngb, wt;
        cin >> src >> ngb >> wt;

        graph[src].push_back(Edge(src, ngb, wt));
        graph[ngb].push_back(Edge(ngb, src, wt));
    }

    int src;
    cin >> src;
    int des;
    cin >> des;

    int criteria;
    cin >> criteria;
    int k;
    cin >> k;

    vector<int> visited(vtces, 0);

    traverse(graph, src, des, criteria, visited, to_string(src), 0);

    cout << "Smallest Path" << spath << "@" << spathWt << endl;
    cout << "Largest Path" << lpath << "@" << lpathWt << endl;
    cout << "CEIL (Just larger path) that " << criteria << " = " << cpath << "@" << cpathWt << endl;
    cout << "FLOOR (Just Smaller path) that " << criteria << " = " << fpath << "@" << fpathWt << endl;

    return 0;
}