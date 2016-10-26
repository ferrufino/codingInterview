

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


/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
 Traverse until middle of linked list
 reverse the other half
 return head of it
 iterate from both heads and compare
 if one different false
 return true
 
 second method: reverse linkedlist
 */

ListNode * reverseList(ListNode *node){
    
    ListNode *prev = NULL;
    ListNode *nxt = NULL;
    
    while(node){
        
        nxt = node->next;
        node->next = prev;
        prev = node;
        node = nxt;
        
    }
    
    return prev;
    
}


bool isPalindrome(ListNode* head) {
    
    if(!head || !head->next) return true;
    ListNode *slow = head;
    ListNode *fast = head;
    
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow->next = reverseList(slow->next);
    slow = slow->next;
    
    while(head && slow){
        
        if(head->val != slow->val)
            return false;
        
        slow = slow->next;
        head = head->next;
        
    }
    
    return true;
}

int main(){
    
    
}
