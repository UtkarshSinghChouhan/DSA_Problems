#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> dirs = {
            {-1, 0}, 

    {0, 1},         {1, 0}, 

            {0, -1}
};

void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>> &q, vector<vector<bool>> &vis){
    int n = grid.size();
    int m = grid[0].size();

    vis[i][j] = true;
    q.push({i, j});

    for(auto &v : dirs){
        int new_i = i + v[0];
        int new_j = j + v[1];

        if(new_i < 0 || new_j < 0 || new_i >= n || new_j >= m || grid[new_i][new_j] == 0 || vis[new_i][new_j] == true){
            continue;
        }

        dfs(grid, new_i, new_j, q, vis);
    }

    return;
}

int multiSourceBFS(vector<vector<int>>& grid, int n, int m, queue<pair<int,int>> &q, vector<vector<bool>> &vis){
    int lvl = 0;

    while(!q.empty()){
        int size = q.size();

        while(size--){
            // remove
            auto &p = q.front();
            q.pop();

            for(auto &v : dirs){
                int new_i = p.first + v[0];
                int new_j = p.second + v[1];

                if(new_i < 0 || new_j < 0 || new_i == n || new_j == m || vis[new_i][new_j] == true){
                    continue;
                }

                if(grid[new_i][new_j] == 1){
                    return lvl;
                }

                vis[new_i][new_j] = true;
                q.push({new_i, new_j});
            }
        }

        lvl++;
    }

    return -1;
}


int main(){
    int n, m;
    cin >>n >> m;

    vector<vector<int>> grid(n, vector<int>(m, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){
            cin >> grid[i][j];
        }
    }


    vector<vector<bool>> vis(n, vector<bool>(m, false));

    queue<pair<int, int >> q;
    bool flag = false;

    // We will run DFS only for one-island and put them in a queue
    for(int i = 0; i < n && !flag; i++){

        for(int j = 0; j < m && !flag; j++){

            if(grid[i][j] == 1 && vis[i][j] == false){

                dfs(grid, i, j, q, vis);
                flag = true;
            }
        }

    }

    cout << multiSourceBFS(grid, grid.size(), grid[0].size(), q, vis);

    return 0;
}