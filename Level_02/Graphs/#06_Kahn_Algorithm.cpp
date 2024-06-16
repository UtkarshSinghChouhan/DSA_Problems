#include<iostream>
#include<vector>
#include<queue>

using namespace std;


// Directed Un-weighted Graph
class Edge{
    public:
    int src;
    int ngb;

    Edge(int src, int ngb){
        this->src = src;
        this->ngb = ngb;
    }
};

void topoSortKahn(vector<vector<Edge>> &graph){
    
    int vtces = graph.size();


    // Step - 01 : Calculate the InDegree of each vertex
    vector<int> inDeg(vtces, 0);

    for(auto &vtx : graph){

        for(auto &edge : vtx){

            inDeg[edge.ngb]++;
        }
    }


    // Kahn Algo
    queue<int> q;

    vector<int> ans;


    for(int i = 0; i < inDeg.size(); i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        ans.push_back(vtx);

        for(auto &edge : graph[vtx]){
            int ngb = edge.ngb;

            inDeg[ngb]--;

            if(inDeg[ngb] == 0){
                q.push(ngb);
            }
        }

        cnt++;
    }

    if(cnt == vtces){
        for(auto &val : ans){
            cout << val << " ";
        }
    }else{
        cout << "Sorting not possible" << endl;
    }



}


int main(){
    int vtces;
    cin >> vtces;

    vector<vector<Edge>> graph(vtces);

    int edges; cin >> edges;

    for(int i = 1; i <= edges; i++){
        int src; cin >> src;
        int ngb; cin >> ngb;

        graph[src].push_back(Edge(src, ngb));
    }

    // for(int i = 0; i < graph.size(); i++){
    //     cout << i << " -> ";

    //     for(auto &edge : graph[i]){
    //         cout << "[" << edge.src << " " << edge.ngb << "], ";
    //     }

    //     cout << endl;
    // }

    topoSortKahn(graph);

    return 0;
}
