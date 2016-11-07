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
#include <unordered_set>

void backtrack(vector<string> &vecStr , string acum, int n, int open = 0, int close = 0){
    
    if(acum.length() == n*2){
        vecStr.push_back(acum);
        return;
    }
    
    if(open > n-1){
        backtrack(vecStr, acum+')', n, open, close+1);
    }else if(open>close){
        backtrack(vecStr, acum+'(', n, open+1, close);
        backtrack(vecStr, acum+')', n, open, close+1);
        
    }else
        backtrack(vecStr, acum+'(', n, open+1, close);
    
}

vector<string> generateParenthesis(int n) {
    string paren = "()";
    
    vector<string> vecStr;
    string acum = "";
    backtrack(vecStr, acum, n);
    
    return vecStr;
    
}

int main()
{
    
    vector<string> str = generateParenthesis(3);
    for(auto e:str){
        cout<<e<<endl;
    }
    
    
}

