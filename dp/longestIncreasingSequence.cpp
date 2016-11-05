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

/* A Naive C/C++ recursive implementation of LIS problem */
#include<stdio.h>
#include<stdlib.h>

/* To make use of recursive calls, this function must return
 two things:
 1) Length of LIS ending with element arr[n-1]. We use
	max_ending_here for this purpose
 2) Overall maximum as the LIS may end with an element
	before arr[n-1] max_ref is used this purpose.
 The value of LIS of full array of size n is stored in
 *max_ref which is our final result */


/*
 This approach works for
 - longest increasing subsequence
 - longest increasing consecutive subsequence
 
 */


/*
 Inefficient recursive approach
 */
int _lis( int arr[], int n, int *max_ref)
{
    
    if (n == 1)
        return 1;
    
    int res, max_ending_here = 1;   // 'max_ending_here' is length of LIS ending with arr[n-1]
    
    
    for (int i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        
        if (arr[i-1]+1 == arr[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
    
    if (*max_ref < max_ending_here){
        *max_ref = max_ending_here;
        
    }
    
    return max_ending_here;
}

/*
 DP with tabulation
 */
/* lis() returns the length of the longest increasing
 subsequence in arr[] of size n */
int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
    
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
    
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) // if it were consecutive only arr[i] == arr[j]+1 would do.
                lis[i] = lis[j] + 1;
    
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
    
    /* Free memory to avoid memory leak */
    free(lis);
    
    return max;
}

/*
 1. lis[i] < lis[j] + 1, to update only if the new value will give the higher value than what exists
 
 2. if if arr[i] > arr[j] and lis[i]< lis[j] + 1 condition is true, you got a sub-sequence which has length 1 higher than the lis found till arr[0] to arr[i-1]
 */

/* Driver program to test above function */
int main()
{
    int arr[] = { 9, 22, 10, 60, 11 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n",
           lis( arr, n ));
    return 0;
}

