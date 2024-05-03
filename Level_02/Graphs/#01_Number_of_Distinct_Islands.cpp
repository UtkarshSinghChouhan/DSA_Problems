#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<string> s;

// directions
vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
string asf = "";

void dfs(vector<vector<int>> &grid, int i, int j){
    if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0){
        return;
    }

    grid[i][j] = 0;  //mark visited

    // asf += "t";
    // dfs(grid, i - 1, j);
    // asf += "r";
    // dfs(grid, i , j + 1);
    // asf += "b";
    // dfs(grid, i + 1, j);
    // asf += "l";
    // dfs(grid, i , j -1);

    // asf += "z";


    for(auto &v : dirs){
        if(v[0] == -1) asf += "t";
        else if(v[1] == 1) asf += "r";
        else if(v[0] == 1) asf += "b";
        else if(v[1] == -1) asf += "l";
        dfs(grid, i + v[0], j + v[1]);
    }

    asf += "z";

    return;
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
        
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(grid[i][j] == 1){
                asf = "x";
                dfs(grid, i, j);
                s.insert(asf);
                
            }
        }

    }

    cout << s.size() << endl;
    return 0;
}