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


// Find the length of the longest consecutive increasing integers inside an array


// [1] -> 1
// [5,4,3,2] -> 1



//  1 1 1 1 2 3
/*
 Approach #1
 T O(n)
 S O(n)
 
 */

int lengthOfLongestConsecutiveNumbers(vector<int> nums){
    
    if(!nums.size()) return 0;
    
    int maxAcum = 1;
    int n = nums.size();
    vector<int> vec(n,0);
    vec[0] = 1;
    
    for(int i = 1; i<n; i++){
        
        if(nums[i-1]+1 == nums[i]){
            vec[i] = vec[i-1] +1;
        }else{
            vec[i] = 1;
        }
        
        if(vec[i]> maxAcum){ //<-
            maxAcum = vec[i];
        }
    }
    
    return maxAcum;
}
/*
 Approach #2
 T O(n)
 S O(1)
 
 */
int lengthOfLongestConsecutiveNumbersConstantMemory(vector<int> nums){
    
    if(!nums.size()) return 0;
    
    int maxAcum = 1;
    int count = 1;
    
    
    for(int i = 1; i<nums.size(); i++){
        
        if(nums[i-1]+1 == nums[i]){
            count = count +1;
        }else{
            count = 1;
        }
        
        if(count> maxAcum){ //<-
            maxAcum = count;
        }
    }
    
    return maxAcum;
}
int main(){
    
    
}
