

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iterator>
#include <set>
#include <unordered_set>

/*
 
 Time Complexity: O(n^4)
 The time complexity can be easily reduced to O(n^3) by pre-calculating sum of frequencies instead of calling sum() again and again.
 
 Space Complexity: O(n^2)
 
 http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/
 */


int sum (vector<int> freq, int i, int j){
    
    int s=0;
    for (int x=i; x<=j; x++) {
        s+=freq[x];
    }
    
    return s;
}

int optimalSearchTree(vector<int> keys, vector<int> freq){
    
    
    int n = keys.size();
    int cost[n][n];
    
    
    
    
    for (int i = 0; i < n; i++) {
        cost[i][i] = keys[i];
    }
    
    for (int L=2; L<=n; L++) {
        
        for (int i = 0; i<= n-L+1; i++) {
            
            int j = i+L-1;
            cost[i][j] = INT_MAX;
            
            for (int r=i; r<=j; r++) {
                
                
                int c = ((r > i)? cost[i][r-1]:0) +
                ((r < j)? cost[r+1][j]:0) +
                sum(freq, i, j);
                
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
                
            }
        }
    }
    
    return cost[0][n-1];
}


int main(){
    
    vector<int> keys = {10,12,16,21,56};
    vector<int> freq = {4,2,6,3,1};
    
    cout<<optimalSearchTree(keys, freq)<<endl;
    
    //    int n = keys.size();
    //    vector<vector<int>> cost( n,vector<int>( n,0 )) ;
    //
    //    cout<<cost.size()<<" "<<cost[0].size()<<endl;
    
    
}
