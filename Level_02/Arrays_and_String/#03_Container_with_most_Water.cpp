#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// brute force
int solution(vector<int> &heights){
    int size = heights.size();
    int max_area = INT_MIN;

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            int height = min(heights[i], heights[j]);
            int breadth = (j - i);
            max_area = max(max_area, height*breadth);
        }
    }

    return max_area;
}

// optimized approach
int solutionOptimized(vector<int> &heights){
    int i = 0, j = heights.size() - 1;
    int water = INT_MIN;
    
    while(i < j){
        int w = j - i;
        int h = min(heights[i], heights[j]);
        water = max(water, w * h);
        (heights[i] <= heights[j])  ? i++ : j--;
    }

    return water;
}

int main(){
    int n; cin >> n;
    vector<int> heights;

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        heights.push_back(val);
    }

    // cout << solution(heights);
    cout << solutionOptimized(heights);

    return 0;
}
