

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
 N size of word list
 n length of a word
 Time Complexity: n*26*N*1 Average time  - n^2*N Worst Time
 Space Complexity: O(N)
 
 */


void addNext(string word,unordered_set<string>& wordList, queue<string> &toVisit ){
    wordList.erase(word);
    for(int i = 0; i<word.length(); i++){
        char temp = word[i];
        for(int j= 0; j<26; j++){
            
            word[i] = 'a'+j;
            
            if(wordList.find(word)!=wordList.end()){
                toVisit.push(word);
                wordList.erase(word);
            }
        }
        
        word[i] = temp;
    }
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    int dist = 2;
    queue<string> toVisit;
    wordList.insert(endWord);
    addNext(beginWord,wordList, toVisit);
    
    while(!toVisit.empty()){
        
        int sizeQ = toVisit.size();
        for(int i = 0; i<sizeQ; i++){
            string temp = toVisit.front(); toVisit.pop();
            
            if(temp == endWord) return dist;
            
            addNext(temp, wordList, toVisit);
            
        }
        dist++;
    }
    
    return 0;
    
}


int main(){
    unordered_set<string> wordDict = {"hot","dot","lot","log"};
    string ew = "cog";
    string bw = "hit";
    
    cout<<ladderLength(bw, ew, wordDict)<<endl;
    
}
