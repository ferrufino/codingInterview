/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeLL(ListNode *list1, ListNode *list2){
        
        if (list1 == NULL) {
            return list2;
        }
        else if (list2 == NULL) {
            return list1;
        }
        
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }
            
            current = current->next;
        }
        
        if (list1 != NULL) {
            current->next = list1;
        }
        
        if (list2 != NULL) {
            current->next = list2;
        }
        
        return dummy.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        
        queue<ListNode *> q;
        for (auto n : lists) {
            q.push(n);
        }
        
        while (q.size() > 1) {
            ListNode *l1 = q.front();
            q.pop();
            ListNode *l2 = q.front();
            q.pop();
            q.push(mergeLL(l1, l2));
        }
        
        return q.front();
    }
};
