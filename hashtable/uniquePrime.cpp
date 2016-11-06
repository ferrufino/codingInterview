

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
    int countPrimes(int n)
    {
        if(n < 3) return 0;
        bool *numbers = new bool[n];
        memset(numbers, 1, sizeof(bool)*n);
        int count = n/2;
        for(int i = 3; i <= sqrt(n); i += 2)
            if(numbers[i])
                for(int j = i*i, k = i<<1; j < n; j += k)
                {
                    if(numbers[j]) count--;
                    numbers[j] = false;
                }
        return count;
    }
};
int main(){
      
}
