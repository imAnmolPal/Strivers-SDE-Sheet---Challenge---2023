// 1. Rotate a LinkedList

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
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases 
        if(!head or !head->next or k==0) return head;

        // compute the length
        ListNode *cur = head;
        int len = 1;

        while(cur->next){
        	len++;
        	cur = cur->next;
        }

        // make last node point to head 
        cur->next = head;

        k = k%len;

        k = len - k;

        // bec we are just before original head, so going (N-K) steps ahead
        while(k--){
        	cur = cur->next;
        }

        // make the next node head
        head = cur->next;
        cur->next = NULL;

        return head;
    }
};