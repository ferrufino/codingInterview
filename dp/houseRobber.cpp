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

int rob(vector<int>& nums) {
    if(!nums.size()) return 0;
    int maxAns = 0;
    vector<int> vec(nums.size(),0);
    int vecSize = vec.size();
    for(int i = 0; i<vecSize; i++){
        
        if(i<2){
            vec[i] = nums[i];
        }else{
            for(int j = 0; j<i-1; j++){
                
                vec[i] = max(vec[i], vec[j]+nums[i]);
            }
        }
        
        if(maxAns<vec[i]){
            maxAns = vec[i];
        }
        
    }
    for (auto e: vec) {
        cout<<e<<" ";
    }
    cout<<endl;
    return maxAns;
}

int main(){
    
    vector<int> vec = {5,6,7,0,1,8};
    
    cout<<rob(vec)<<endl;
}
