

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iterator>
#include <set>

/*
 Time Complexity: O(n*m)
 Space Complexity: O(n*m)
 n is the row size and m the column size
 
 1's are represented as rocks
 */
/*
Approach:
create matrix of same dimensions
copy first row and column, if it is a rock 0 else a 1
traverse matrix from second row and second col
if is a rock at pos i,j equals 0
else
max of one before, diagonal left, or up
*/
pair<int,int> location;
int size;

void findMax(vector<vector<int>> m){
    
    int tempSize = 0;
    pair<int,int> tempLocation;
    
    for (int i = 0; i<m.size(); i++) {
        for (int j = 0; j<m[0].size(); j++) {
            
            if(m[i][j]>tempSize){
                
                tempSize = m[i][j];
                tempLocation = {i,j};
            }
        }
    }
    
    location = tempLocation;
    size = tempSize;
    
}


void findPerfectsquare(vector<vector<int>> m){
    
    vector<vector<int>> dp(m.size(), vector<int>(m[0].size()));
    
    for (int i = 0; i<dp.size(); i++) {
        
        dp[i][0] = m[i][0] == 1? 0:1;
    }
    for (int j = 0; j<dp[0].size(); j++) {
        
        dp[0][j] = m[0][j] == 1? 0:1;
    }
    
    for(int i = 1; i<m.size(); i++){
        
        for(int j = 1; j<m[0].size(); j++){
            
            if(m[i][j] == 1){
                dp[i][j] = 0;
            }else{
                
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            }
            
        }
        
    }
    
    findMax(dp);
    
    
}


int main(){
    
    vector<vector<int>> temp = {{1,0,1,1},{0,0,0,1},{0,0,0,0},{0,0,0,1}};
    
    findPerfectsquare(temp);
    
    cout<<location.first<<" "<<location.second<<" "<<size;
    
    
    
    
}
