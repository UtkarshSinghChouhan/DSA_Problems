
// 1. You are given a number n (representing the number of students). Each student will have an id
//      from 0 to n - 1.    //n = no. of vertices
// 2. You are given a number k (representing the number of clubs)  // k = number of edges
// 3. In the next k lines, two numbers are given separated by a space. The numbers are ids of
//      students belonging to same club.           //  it represents the edges connecting the two vertices
// 4. You have to find in how many ways can we select a pair of students such that both students are
//      from different clubs.

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

    // total number of ways we can select a pair of students such that they belong to the different clubs
    int total = 0;
    for (int i = 0; i < connected_comp.size() - 1; i++)
    {
        for (int j = i + 1; j < connected_comp.size(); j++)
        {
            total += connected_comp[i].size() * connected_comp[j].size();
        }
    }

    cout << total << endl;

    return 0;
}

// Input
// 7
// 5
// 0 1
// 2 3
// 4 5
// 5 6
// 4 6

// Output
// 16