

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

unordered_map<string, vector<string>> m;

vector<string> combine(string word, vector<string> prev){
    for(int i=0;i<prev.size();++i){
        prev[i]+=" "+word;
    }
    return prev;
}

void printResult(vector<string> r, string s){
    cout<<s<<": ";
    for(auto e : r) {
        cout<<e<<"    ";
    }
    cout<<endl;
}

vector<string> wordBreak(string s, unordered_set<string>& dict) {
    if(m.count(s)) return m[s]; //take from memory
    vector<string> result;
    if(dict.count(s)){ //a whole string is a word
        result.push_back(s);
    }
    for(int i=1;i<s.size();++i){
        string word=s.substr(i);
        if(dict.count(word)){
            string rem=s.substr(0,i);
            
            //cout<<"rem: "<<rem<<endl;
            
            vector<string> prev=combine(word,wordBreak(rem,dict));
            
            //printResult(prev, "prev");
            result.insert(result.end(),prev.begin(), prev.end());
            
            printResult(result, "result");
            cout<<endl;
            
        }
    }
    cout<<"s: "<<s<<endl;
    printResult(result, "result about to be saved");
    m[s]=result; //memorize
    return result;
}
int main(){
    
    unordered_set<string> dict = {{"cats"},{"cat"},{"and"},{"sand"},{"dog"}};
    vector<string> ans = wordBreak("catsanddog", dict);
    cout<<endl;
    for (auto e:ans) {
        cout<<e<<endl;
    }
    
    
    
    
}
