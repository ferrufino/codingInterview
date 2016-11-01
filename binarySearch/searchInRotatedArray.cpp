

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
class Solution {
public:
    
    
    int search(vector<int>& arr, int key)
    {
        int n = arr.size();
        int pivot = findPivot(arr, 0, n-1);
        
        // If we didn't find a pivot, then array is not rotated at all
        if (pivot == -1)
            return binarySearch(arr, 0, n-1, key);
        
        // If we found a pivot, then first compare with pivot and then
        // search in two subarrays around pivot
        if (arr[pivot] == key)
            return pivot;
        if (arr[0] <= key)
            return binarySearch(arr, 0, pivot-1, key);
        return binarySearch(arr, pivot+1, n-1, key);
    }
    
    /* Function to get pivot. For array 3, 4, 5, 6, 1, 2 it returns
     3 (index of 6) */
    int findPivot(vector<int> arr, int low, int high)
    {
        // base cases
        if (high < low)  return -1;
        if (high == low) return low;
        
        int mid = low + (high - low)/2;   /*low + (high - low)/2;*/
        if ( arr[mid] > arr[mid + 1])
            return mid;
        if ( arr[mid] < arr[mid - 1])
            return (mid-1);
        if (arr[low] >= arr[mid])
            return findPivot(arr, low, mid-1);
        return findPivot(arr, mid + 1, high);
    }
    
    /* Standard Binary Search function*/
    int binarySearch(vector<int>arr, int low, int high, int key)
    {
        if (high < low)
            return -1;
        int mid = (low + high)/2;  /*low + (high - low)/2;*/
        if (key == arr[mid])
            return mid;
        if (key > arr[mid])
            return binarySearch(arr, (mid + 1), high, key);
        return binarySearch(arr, low, (mid -1), key);
    }
    
    
};

int main(){
    
    
}
