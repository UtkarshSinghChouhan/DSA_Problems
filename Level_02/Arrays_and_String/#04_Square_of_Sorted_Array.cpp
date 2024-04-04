#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// BRUTE FORCE
vector<int> solution(vector<int> & arr){
    vector<int> res;

    // step 01 - Square
    for(auto & val : arr){
        res.push_back(val * val);
    }

    // Step 02 - Sort
    sort(res.begin(), res.end());

    return res;
}

// OPTIMIZED
vector<int> solutionOptimized(vector<int> & arr){
    int i = 0, j = arr.size() - 1, idx = arr.size() - 1;
    vector<int> res(arr.size(), 0);

    while( i <= j){
        if(abs(arr[i]) >= abs(arr[j])){
            res[idx] = arr[i] * arr[i];
            i++;
        }else{
            res[idx] = arr[j] * arr[j];
            j--;
        }
        idx--;
    }

    return res;
}


int main(){
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        arr.push_back(val);
    }

    // vector<int> res = solution(arr);
    vector<int> res = solutionOptimized(arr);
    for(auto & val : res){
        cout << val << " ";
    }
    return 0;
}