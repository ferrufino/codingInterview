

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
/*
 
 Stating value is the left most
 A->1
 AB ->28
 BA -> 53 - 2+0*26, 1+2*26
 
 therefore loopong from the first value,
 every next value will have to add its
 corresponding representation in number s[i]-'A'+1 so is s[i] = A this equals 1 and not 0
 and add the acumulative times 26, starting from acumulative variable equal to 0
 */

int titleToNumber(string s) {
    int num = 0;
    for(int i = 0; i<s.length(); i++){
        
        num = s[i]-'A'+1 + num*26;
    }
    
    return num;
}




int main ()
{
    
    
    cout<<titleToNumber("BA");
}
