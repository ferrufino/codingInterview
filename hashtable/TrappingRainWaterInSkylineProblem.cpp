


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

vector<int> getCoordinates(vector<pair<int,int>> pos){
    
    vector<int> vec;
    vec.push_back(0);
    int p = 0;
    int latestHeight = 0;
    for(int i = 0; i<=pos.back().first; i++) {
        
        if(pos[p].first == i){
            latestHeight = pos[p].second;
            vec.push_back(pos[p].second);
            p++;
        }else{
            vec.push_back(latestHeight);
        }
        
    }
    
    return vec;
}





int getWater(vector<pair<int,int>> pos){
    
    vector<int> arr = getCoordinates(pos);
    arr.erase(arr.begin()+1);
    for (int i = 0; i<arr.size(); i++) {
        cout<<"i: "<<i<<" val: "<<arr[i]<<endl;
    }
    cout<<endl;
    
    int n = arr.size();
    
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
    
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
    
    // Initialize result
    int water = 0;
    
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i-1], arr[i]);
    
    // Fill right array
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
        right[i] = max(right[i+1], arr[i]);
    
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i],right[i]) - arr[i];
    
    
    return water;
}

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
    
    //vector<vector<int>> vec = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    
    //cout<<calculateMinimumHP(vec);
    vector<vector<int>> input = { {2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<pair<int,int>> ans = getSkyline(input);
    cout<<getWater(ans)<<endl;
    
    
}
