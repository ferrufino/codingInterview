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
public:
    /*Appraoch #1: 19ms*/
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> rst;
        stack<TreeNode*>stk;
        TreeNode *ptr = root;
        while (ptr || !stk.empty()) {
            if (ptr) {
                stk.push(ptr);
                ptr = ptr->left;
            }
            else {
                ptr = stk.top(); stk.pop();
                if (rst.size() == k && abs((double)rst.front()-target) > abs((double)ptr->val-target)) {
                    rst.erase(rst.begin());rst.push_back(ptr->val);
                }
                else if (rst.size() < k) rst.push_back(ptr->val);
                else break;
                ptr = ptr->right;
            }
        }
        return rst;
    }
};

/*My approach: 32ms*/
vector<int> closestKValues(TreeNode* root, double target, int k) {
    
    priority_queue<pair<double, int>> pq;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        
        TreeNode *aux = q.front();
        q.pop();
        
        long tempValue = fabs(aux->val-target);
        
        pq.push(make_pair(fabs(target - double(aux->val)), aux->val));
        
        if(pq.size() > k)
            pq.pop();
        
        
        if(aux->left)
            q.push(aux->left);
        
        if(aux->right)
            q.push(aux->right);
    }
    vector<int> vec;
    int sz = pq.size();
    for(int i=0; i<sz; i++){
        vec.push_back(pq.top().second);
        pq.pop();
    }
    
    return vec;
}
/*Approach #3: 33ms*/

void dfs(TreeNode* root, priority_queue<pair<double, int>>& pq, double target, int k) {
    if(!root) return;
    
    pq.push(make_pair(fabs(target - double(root->val)), root->val));
    
    if(pq.size() > k)
        pq.pop();
    
    dfs(root->left, pq, target, k);
    dfs(root->right, pq, target, k);
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<pair<double, int>> pq;
    vector<int> result;
    
    dfs(root, pq, target, k);
    while(!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    
    return result;
}
