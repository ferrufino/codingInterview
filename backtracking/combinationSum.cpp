

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

void backtrack(vector<int> candidate, vector<int>& candidates, int target, vector<vector<int>> &ans, int position = 0){
    
    if(target < 0)
        return;
    
    if(target == 0){
        ans.push_back(candidate);
        return;
    }
    
    for(int i = position; i<candidates.size(); i++){
        if(candidates[i]>target) break;
        candidate.push_back(candidates[i]);
        backtrack(candidate, candidates, target-candidates[i], ans, i);
        candidate.pop_back();
    }
    
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
    if(candidates.empty() || !target) return vector<vector<int>>();
    vector<vector<int>> ans;
    vector<int> candidate;
    
    sort(candidates.begin(), candidates.end());
    backtrack(candidate, candidates, target, ans);
    
    return ans;
}
int main(){
    
}
