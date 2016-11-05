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

struct TrieNode {
    TrieNode *children[26] = {NULL};
    TrieNode();
    bool isNode = false;
};

class Trie{
    
private:
    TrieNode *root;
    
    bool search(string s, bool isPrefix){
        
        TrieNode *current = root;
        for(auto c:s){
            int index = c - 'a';
            if(!current->children[index])
                return false;
            current = current->children[index];
        }
        
        return isPrefix || current->isNode;
    }
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        
        TrieNode *current = root;
        
        for(auto c:word){
            int index = c-'a';
            if(!current->children[index])
                current->children[index] = new TrieNode();
            current = current->children[index];
        }
        current->isNode = true;
    }
    
    bool search(string word){
        return search(word,false);
    }
    
    bool startsWith(string prefix){
        return search(prefix, true);
    }
    
};

int main()
{
    
    
    return 0;
}

