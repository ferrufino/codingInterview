

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
 
 // if root null return null
 // if p or q equal root return root
 
 call func recursively for left and right
 assign l and r respectively
 
 if l is null
 then lca must be on the right subtree return that
 if r is null
 then lca must be on the lest subtree return that
 
 if both p and q exist then p and q belong to different subtrees and
 that implies lca has been found
 return root
 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if(!root || root == p || root == q)
        return root;
    
    TreeNode *l = lowestCommonAncestor(root->left, p,q);
    TreeNode *r = lowestCommonAncestor(root->right, p,q);
    
    if(!l)
        return r;
    else if(!r)
        return l;
    
    return root; // both node are in diff paths
}
int main(){
    
    
}
