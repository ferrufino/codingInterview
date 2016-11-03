

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

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int x = dungeon.size() - 1, y = dungeon[0].size() - 1;
    vector<int> dp(y + 1, 0);
    
    dp[y] = dungeon[x][y] >= 0 ? 1 : 1 - dungeon[x][y];
    
    for (int i = x; i >= 0; i--)
        for (int j = y; j >= 0; j--) {
            if (i == x && j == y) continue;
            
            ///
            cout<<"i: "<<i<<" j: "<<j<<endl;
            
            int down = INT_MAX;
            if (i < x) {
                if (dungeon[i][j] >= dp[j])
                    down = 1;
                else
                    down = dp[j] - dungeon[i][j];
            }
            ///
            cout<<"down: "<<down<<endl;
            
            int right = INT_MAX;
            if (j + 1 <= y) {
                if (dungeon[i][j] >= dp[j + 1])
                    right = 1;
                else
                    right = dp[j + 1] - dungeon[i][j];
            }
            ///
            cout<<"right: "<<right<<endl;
            
            
            dp[j] = min(down, right);
            ///
            cout<<"dp[j]: "<<dp[j]<<endl;
            
            
            for(auto e: dp){
                cout<<e<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
    return dp[0];
}
