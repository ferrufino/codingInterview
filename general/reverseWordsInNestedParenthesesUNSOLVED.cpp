

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
 have loop traverse and find first ( and corresponding last )  => what if ((a).. (a))
 for each initial and final pos at same level in stack, call recursive func
 if level is greater than 0 and no parenthesis found, reverse word - use reference.
 
 
 Approach 2
 push words at a certain level, with there posi and posf <- map of vector of pairs, key is level
 just from max to 1 start reversing
 
 
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

void reverseString(string &s, int posi, int posj, int level){
    
    for(int i = posi; i<posj; i++){
        
        if(s[i] == '('){
            int j=i; int count = 0; bool paren = false;
            while(j<s.length()){
                
                if(s[j] == '(' || s[j] == ')')
                    paren=true;
                
                
                if(s[j]==')' && count <=0)
                    break;
                else if(s[j]==')'){
                    count--;
                }else if(s[j]=='('){
                    level++;
                    count++;
                }
                
                j++;
            }
            
            if(!paren && level>0){
                cout<<"entre"<<endl;
                reverseS(s,i+1,j-1);
            }else
                reverseString(s, i+1, j-1, level+1);
            
            
        }
    }
    
}

int main(){
    
    string s = "foo(baz(bar))blim";
    
    
    reverseString(s, 0, s.length(), 0);
    string ans = "";
    for (int i =0; i<s.length(); i++) {
        if(s[i] != '(' && s[i] != ')'){
            ans+=s[i];
        }
    }
    
    cout<<ans;
    
}
