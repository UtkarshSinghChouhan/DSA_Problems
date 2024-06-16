#include<iostream>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

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

typedef pair<int, int> p;

void dijkstra(vector<vector<Edge>> &graph, int src, int tar){
    int size = graph.size();

    vector<bool> vis(size, false);

    priority_queue<p, vector<p>, greater<p>> pq;     //cost_so_far   vs   src


    pq.push({0, src});

    while(!pq.empty()){
        // remove
        auto val = pq.top();
        pq.pop();

        // mark visited
        int src = val.second;
        int csf = val.first;
        vis[src] = true;



        if(src == tar){
            cout << csf << endl;
            return;
        }

        // add unvisited neighbour
        for(auto &edge : graph[src]){
            int ngb = edge.ngb;
            int wt = edge.wt;

            if(vis[ngb] == false){


                pq.push({csf + wt, ngb});

            }
        }

    }

    cout << -1 << endl;
    return;

}

void zero_one_BFS(vector<vector<Edge>> &graph, int src, int tar){
    deque<p> dq;

    vector<bool> vis(graph.size(), false);

    dq.push_front({0, src});

    while(!dq.empty()){        

        // remove
        auto val = dq.front();
        dq.pop_front();

        // mark visited
        int src = val.second;  
        int csf = val.first;      
        vis[src] = true;


        if(src == tar){
            cout << csf << endl;
            return;
        }

        for(auto &edge : graph[src]){
            int ngb = edge.ngb;
            int wt = edge.wt;

            if(vis[ngb] == false){

                if(wt == 0){

                       // add to the front
                    dq.push_front({csf + wt, ngb});
                    
                }else{

                       // add to the back
                    dq.push_back({csf + wt, ngb});

                }
            }

        }
    
    }

    cout << -1 << endl;
    return;
}

int main(){
    int vtces, edges;
    cin >> vtces >> edges;

    vector<vector<Edge>> graph(vtces + 1);

    for(int i = 0; i < edges; i++){
        int src, ngb, wt;

        cin >> src >> ngb >> wt;

        graph[src].push_back(Edge(src, ngb, wt));        
        graph[ngb].push_back(Edge(ngb, src, wt + 1));        
    }

    int src, tar;
    cin >> src >> tar;

    // dijkstra(graph, src, tar);

    zero_one_BFS(graph, src, tar);

    return 0;
}