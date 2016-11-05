/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int ans = INT_MIN;
public:
    int maxSum(TreeNode *root){
        if(!root) return 0;
        
        int l = maxSum(root->left);
        int r = maxSum(root->right);
        
        ans = max(ans, (max(0,l) + max(0,r) + root->val));
        return root->val + max(0,max(l, r));
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};
