#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> &puzzle){
        int n = puzzle.size(), m = puzzle[0].size();        

        string pzl = "";
        string tar = "123450";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pzl += to_string(puzzle[i][j]) ;
            }
        }

        vector<vector<int>> dirs = {{1, 3}, {0, 4, 2}, {1, 5}, {0, 4}, {3, 1, 5}, {4, 2}};

        queue<string> q;
        q.push(pzl);

        int lvl = 0;

        set<string> s;
        s.insert(pzl);


        while(!q.empty()){
            int size = q.size();

            while(size--){
                // remove
                string front = q.front();
                q.pop();


                  
                if(front == tar){
                    return lvl;
                }



                // finding the place of "0"
                int idx = -1;
                for(int i = 0; i < 6; i++){
                    if(front[i] == '0'){
                        idx = i;
                        break;
                    }
                }


                for(auto &pos : dirs[idx]){

                    string state = front;

                    
                       // swap "0" with the char at pos
                    swap(state[idx], state[pos]);

                  
                       // push the new string in the queue only if it is unvisited and mark it visited
                    if(s.find(state) == s.end()){
                        q.push(state);
                        s.insert(state);
                    }


                    
                }
            }

            lvl++;
        }     
        
    return -1;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> puzzle(n, vector<int>(m, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> puzzle[i][j];
        }
    }

    cout << solution(puzzle);

    return 0;
}