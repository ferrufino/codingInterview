

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

//Solve problem: longest consecutive length of path in a bt


/*
 BT or BST?
 nodes must follow same orientation? Just left or just right?
 Null root -> 0
 One node -> 1, so default value 1
 
 
 Approach:
 Recursively keep track of
 next consecutive number,
 current length,
 maxlength
 */
struct TreeNode {
    TreeNode(int v){val = v;}
    int val=0;
    TreeNode *left = {NULL};
    TreeNode *right = {NULL};
};


void findLCP(TreeNode *root, int &maxNum, int nextExpectedVal, int currentMax = 1 ){
    
    
    if(!root)
        return;
    if(root->val == nextExpectedVal){
        currentMax +=1;
        nextExpectedVal+=1;
        maxNum = max(currentMax, maxNum);
        
        findLCP(root->left, maxNum, nextExpectedVal, currentMax);
        findLCP(root->right, maxNum, nextExpectedVal, currentMax);
        
        
    }else{
        currentMax = 1;
        nextExpectedVal = root->val+1;
        findLCP(root->left, maxNum, nextExpectedVal, currentMax);
        findLCP(root->right, maxNum, nextExpectedVal, currentMax);
    }
    
}




int lcp(TreeNode *root){
    
    int max = 1;
    findLCP(root->left, max, root->val+1);
    findLCP(root->right, max, root->val+1);
    return max;
}

int main (){
    // TreeNode *a = new TreeNode(6);
    // TreeNode *b = new TreeNode(9);
    // TreeNode *c = new TreeNode(7);
    // TreeNode *d = new TreeNode(10);
    // TreeNode *e = new TreeNode(11);
    // a->left = b;
    // b->left = c;
    // b->right = d;
    // d->right = e;
    
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    a->left = b;
    b->left = c;
    c->left = d;
    a->right = e;
    cout<<lcp(a);
    
}
