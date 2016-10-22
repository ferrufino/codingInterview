

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

/*
 Time Complexity O()
 Space Complexity
 
 */


struct node{
    
    node *left = NULL;
    node *right = NULL;
    int val;
    
    node(int v){val=v;}
    
};


node* flipTree(node *root){
    
    if(!root) return NULL;
    
    if(!root->left && !root->right)
        return root;
    
    node *flippedBinaryTree = flipTree(root->left);
    
    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL;
    
    
    return flippedBinaryTree;
}

int main(){
    
    node *t = new node(2);
    
    node *a = new node(3);
    
    //node *b = new node(1);
    
    t->left = a;
    //t->right = b;
    
    t = flipTree(t);
    
    cout<<t->val<<endl<<t->right->val<<" "<<endl;
    
    
    
    
}
