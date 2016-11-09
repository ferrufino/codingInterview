

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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 
 diff must be double to handle integer oveflows.
 */

int closestValue(TreeNode* root, double target) {
    int res = root->val;
    double diff = abs(root->val * 1.0 - target);
    
    while(root != nullptr){
        double d = abs(root->val * 1.0 - target);
        if(diff > d){
            res = root->val;
            diff = d;
        }
        if(target < root->val){root = root->left;}
        else{root = root->right;}
    }
    return res;
}

int main (){
    TreeNode *a = new TreeNode(1500000000);
    TreeNode *b = new TreeNode(1400000000);
    a->left = b;
    double t = -1500000000.0;
    
    cout<<closestValue(a, t );
}
