/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // you can use a recursive function that checks the running head with the running tail
    bool isPalindrome(ListNode* head) {
        return recursive(head, head);
    }
    
    // we can update the running head by passing by reference
    bool recursive(ListNode*& runningHead, ListNode* runningTail) {
        // at the end of the tail, return for true as base case
        if (runningTail == nullptr) return true;
        // at any point, check with the runningHead, then update both
        int nodeAfterIsPal = recursive(runningHead, runningTail->next);
        if (!nodeAfterIsPal) return false;
        if (runningHead->val != runningTail->val) return false; 
        runningHead = runningHead->next; 
        return true; 
    }
};