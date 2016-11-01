

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


// O Logn


int findNum(vector<int> nums){
    
    int start = 0;
    int end = nums.size()-1;
    
    while(start<end){
        
        int mid = start + (end-start)/2;
        cout<<start<<" "<<end<<" "<<mid<<endl;
        if(mid/3+1 != nums[mid]){
            
            if(mid%3 == 0){
                
                if(mid+2<nums.size() && nums[mid] != nums[mid+2]){
                    return nums[mid];
                }else{
                    end = mid-1;
                }
            }else if(mid+1<nums.size() && nums[mid] != nums[mid+1]){
                
                if(mid-3<0)
                    return nums[mid];
                
                if(nums[mid-1] == nums[mid] && nums[mid-2] == nums[mid] ){
                    end = mid-3;
                }else{
                    end = mid;
                }
                
            }else{
                if(mid-2<0)
                    return nums[mid];
                end = mid-2;
            }
        }else{
            
            if(mid%3 == 0){
                if(nums[mid] != nums[mid+2])
                    end = mid;
                else
                    start = mid+3;
            }else if(nums[mid] != nums[mid+1]){
                if(nums[mid] == nums[mid-1] && nums[mid] == nums[mid-2])
                    start = mid+1;
                else
                    return nums[mid];
            }else{
                if(nums[mid] == nums[mid+1] && nums[mid] == nums[mid-1])
                    start = mid+2;
                else
                    return nums[mid];
            }
            
        }
    }
    
    if(start>=nums.size() || start<0)
        return -1;
    return nums[start];
}

int main(){
    vector<int> nums = {1,1,1,2,2,2,3,3,4,4,4};
    cout<<findNum(nums)<<endl;
    
}
