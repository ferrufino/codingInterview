

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
 Write a method that for a given input string, reverse all the characters inside parentheses. Consider nested parentheses.
 "foobarbaz" => foobarbaz
 "foo(bar)baz" => foorabbaz
 "foo(bar(baz))blim" => foo(barzab)blim => foobazrabblim
 */

/*
 Approach 1
 push to stack openparan postitions of opening parentheses
 push to stack closeparan positions of closing parentheses
    -validate size of stacks consitency
 
 validate they have same size
 
 while both stacks not empty
    pop the two top values in stack
    and reverse words in it
 
erase parentheses of string
 return string.
 
 */

void reverseS(string &s, int i, int j){
    
    while(i<j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
        i++;
    }
    
}

string reverseString(string s){
    
    stack<int> openPos;
    stack<int> closePos;
    
    for(int i = 0; i<s.length(); i++){
        
        if(s[i] == '(')
            openPos.push(i);
    }
    
    for(int i = 0; i<s.length(); i++){
        
        if(s[i] == ')')
            closePos.push(i);
    }
    
    if(openPos.size() != closePos.size())
        return s;
    
    while(openPos.size()){
    
        int i = openPos.top(); openPos.pop();
        
        int j = closePos.top(); closePos.pop();
        
        reverseS(s,i,j);
    }
    int j = 0;
    for(int i = 0; i<s.length; i++){
        if(s[i] != '(' && s[i] != ')'){
            s[j++] = s[i];
            
        }
    }
    
    return s;
    
}

int main(){
    
    string s = "foo(baz(bar))blim";
    
    
   cout<<reverseString(s);
   
    
}
