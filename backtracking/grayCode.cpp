

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
vector<int> grayCode(int n) {
    vector<int> result;
    result.push_back(0);
    
    for(int i=0;i<n;i++){
        // mirror the result with shift ith digit to 1
        for(int j=result.size()-1;j>=0;j--){
            int cur=result[j]+(1<<i);
            result.push_back(cur);
        }
    }
    
    return result;
}
int main(){
    
}
