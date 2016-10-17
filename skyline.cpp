

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

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    map<int, vector<int>> m;
    for(vector<int> v : buildings){
        m[v[0]].push_back(v[2]);
        m[v[1]].push_back(-v[2]);
    }
    multiset<int> s{0};
    vector<pair<int, int>> res;
    for(auto it = m.begin(); it != m.end(); ++it){
        for(int height : it->second){
            if(height > 0) s.insert(height);
            else s.erase(s.find(-height));
        }
        if(res.empty() || *s.rbegin() != res.back().second){
            cout<<it->first<<" "<<*s.rbegin()<<endl;
            res.push_back({it->first, *s.rbegin()});
            
        }
    }
    return res;
}
int main(){
    vector<vector<int>> input = { {2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<pair<int,int>> ans = getSkyline(input);
    
    
}
