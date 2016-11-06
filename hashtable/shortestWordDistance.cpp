

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
 Shortest Word Distance
 a,a,b,b => 1
 
 push all position to a respective word given (word1 or word2) to a vector
 acum = words.size()-1
 
 loop throught vec1 and vec2
 evaluate if vec1 at i is bigger than vec2 at j
 if true compare and update dist if necessary
 else
 compare and update dist if necessary
 
 */

int shortestWordDistance(vector<string> words, string word1, string word2){
    
    int resp = words.size()-1;
    vector<int> index1, index2;
    for (int i = 0; i<resp; i++) {
        if(words[i] == word1){
            index1.push_back(i);
        }
        if(words[i] == word2){
            index2.push_back(i);
        }
    }
    int j = 0;
    int i = 0;
    while(i<index1.size()-1 && j<index2.size()-1){
        
        if(index1[i]<index2[j]){
            
            if(index2[j]-index1[i] < resp){
                resp = index2[j]-index1[i];
            }
            
            i++;
            
        }else{
            if(index1[i]-index2[j] < resp){
                resp = index1[i]-index2[j];
            }
            
            j++;
            
        }
    }
    
    return resp;
}


int main(){
    
    
}
