// 2. Find the middle of LinkedList

// Approach 1
/*
We can count the total number of nodes first,
using loop and then do half of it. 

Whatever number(say k) we get, we print that kth node from
left. */


// Optimized Approach 

/* 
	We will make use of tortoise method.
	Also know as slow fast method. 
*/
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }

        return slow;
    } 
}; 