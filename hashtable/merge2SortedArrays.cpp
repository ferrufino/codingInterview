

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
 
 Merge
 Uses cur as original size m+n, size there is a scenairo one of the nums is empty
 and if nums 1 is the one empty the value of num2 should be passed to nums1
 
 O(m+n)
 O(1)
 */

void merge(vector<int>& a, int m, vector<int>& b, int n) {
    int cur = m+n;
    int i = m-1;
    int j = n-1;
    while(--cur >= 0){
        
        a[cur] = (i<0 || j>=0 && b[j]>a[i])? b[j--] : a[i--];
        
    }
    
    for(auto e:a){
        cout<<e<<" ";
    }
}

int main ()
{
    vector<int> vec = {1,5,7,8,9,0,0,0,0,0};
    vector<int> vec2 = {2,3,6,10,11};
    merge(vec, 5, vec2, 5);
}
