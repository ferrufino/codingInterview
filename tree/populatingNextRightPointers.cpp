/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeLinkNode* nextChild(TreeLinkNode *cur){
        
        while(cur){
            if(cur->left)
                return cur->left;
            if(cur->right)
                return cur->right;
            cur = cur->next;
        }
        
        return NULL;
        
    }
    
    void connect(TreeLinkNode *root) {
        
        TreeLinkNode* levelStart = root;
        
        while(levelStart){
            TreeLinkNode* cur = levelStart;
            while(cur){
                
                if(cur->left)
                    cur->left->next = cur->right? cur->right: nextChild(cur->next);
                if(cur->right)
                    cur->right->next = nextChild(cur->next);
                
                cur = cur->next;
            }
            
            levelStart = nextChild(levelStart);
            
        }
        
    }
};
