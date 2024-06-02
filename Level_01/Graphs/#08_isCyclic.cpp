#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

class Edge{
public: 
    int src;
    int ngb;

    Edge(int src, int ngb){
        this->src = src;
        this->ngb = ngb;
    }
};

int main(){
    int vtces;
    int edges;

    cin >> vtces >> edges;

    vector<vector<Edge>> graph;

    for(int i = 0 ; i < vtces; i++){
        for(int j = 0; j < edges; j++){
            int src; 
            int ngb;
            cin >> src >> ngb;

            graph[src].push_back(Edge(src, ngb));
            graph[ngb].push_back(Edge(ngb, src));
        }
    }

    return 0;
}