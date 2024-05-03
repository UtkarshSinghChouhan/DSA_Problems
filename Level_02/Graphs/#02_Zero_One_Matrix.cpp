#include<iostream>
#include<limits.h>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(vector<vector<int>> &input, int i, int j){

    int n = input.size(), m = input[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int lvl = -1;
    queue<pair<int, int>> q;
    q.push({i, j});


    while(!q.empty()){
        int size = q.size();
        lvl++;

        while(size > 0){
            auto p = q.front();
            q.pop();

            if(input[p.first][p.second] == 0){
                return lvl;
            }

            for(auto v : dirs){
                
                int new_i = p.first + v[0];
                int new_j = p.second + v[1];

                    // if out of bound
                if(new_i < 0 || new_j < 0 || new_i == n || new_j == m ||  vis[new_i][new_j] == true){
                    continue;
                }

                q.push({new_i, new_j});
                vis[new_i][new_j] = true;
                
            }

            size--;
        }
    }


    return -1;
}


// MultiSource BFS
void multiSourceBFS( vector<vector<int>> &input){
    int n = input.size(),
        m = input[0].size();

    vector<vector<int>> res(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    // Adding all the sources in the queue
    for(int i = 0; i  < n; i++){
        for(int j = 0; j < m; j++){
            if(input[i][j] == 0){
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int size = q.size();

        while(size--){
              // remove
            auto p = q.front();
            q.pop();

            for(auto &v : dirs){
                int new_i = p.first + v[0];
                int new_j = p.second + v[1];

                if(new_i < 0 || new_j < 0 || new_i == n || new_j == m || res[new_i][new_j] > 0 || input[new_i][new_j] == 0){
                    continue;
                }

                q.push({new_i, new_j});
                res[new_i][new_j] = res[p.first][p.second] + 1;
            }
        }
    }

    // Printing the answer
    for(int i = 0; i  < n; i++){
        for(int j = 0; j < m; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> input(n, vector<int> (m));
    vector<vector<int>> res(n, vector<int> (m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input[i][j];
        }
    }

    // BRUTE FORCE

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){

    //         if(input[i][j] == 1){
                
    //             int dis = bfs(input, i, j);
    //             res[i][j] = dis;
    //         }

    //     }
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // MULTISORCE BFS
    multiSourceBFS(input);

    
    return 0;
}