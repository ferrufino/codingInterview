

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

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    
    if (candidates.empty()) { return result; }
    sort(candidates.begin(), candidates.end());
    findCombinationSum(candidates, target, combination, result);
    
    return result;
}

void findCombinationSum(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& result, int startPos = 0) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }
    
    for (int i = startPos; i < candidates.size(); ++i) {
        if (candidates[i] > target) { break; }
        combination.push_back(candidates[i]);
        findCombinationSum(candidates, target - candidates[i], combination, result, i);
        combination.pop_back();
    }
}
int main(){
      
}
