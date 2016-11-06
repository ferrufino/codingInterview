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

int findKth(int k, vector<int> nums1, vector<int> nums2, int s1, int s2){
    if (s1 >= nums1.size()) return nums2[s2+k-1];
    if (s2 >= nums2.size()) return nums1[s1+k-1];
    if (k == 1) return min(nums1[s1], nums2[s2]);
    int m1 = s1 + k/2 - 1, m2 = s2 + k/2 - 1;
    int mid1 = m1 >= nums1.size() ? INT_MAX : nums1[m1];
    int mid2 = m2 >= nums2.size() ? INT_MAX : nums2[m2];
    cout<<"k: "<<k<<" s1: "<<s1<<" s2: "<<s2<<" --- m1: "<<m1<<" m2: "<<m2<<" --- mid1: "<<mid1<<" mid2: "<<mid2<<endl<<endl;
    if (mid1 > mid2) return findKth(k-k/2, nums1, nums2, s1, m2+1);
    return findKth(k-k/2, nums1, nums2, m1+1, s2);
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalLength = nums1.size() + nums2.size();
    int k = totalLength/2;
    
    if(totalLength%2 == 0){
        int n1 = findKth(k+1,nums1,nums2,0,0);
        int n2 = findKth(k,nums1,nums2,0,0);
        cout<<n1<<" "<<n2<<endl;
        return (n1 + n2) / 2.0;
    }else
        return findKth(k+1,nums1,nums2,0,0);
}

int main()
{
    vector<int> n1 = {1,4,7,8,9};
    vector<int> n2 = {2,3,5,6,10};
    cout<<findMedianSortedArrays(n1, n2)<<endl;
    return 0;
}

