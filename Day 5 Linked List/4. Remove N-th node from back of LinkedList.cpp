// 4. Remove N-th node from back of LinkedList

/*
Brute force - 

count the nodes
Kth node from last is (N-K+1)th from starting.

TC - O(n) + O(n)

*/

/*

Optimized Approach- 

We will use slow fast method to solve this. 
Put fast pointer K step away from the slow. 

TC - O(n)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
		dummy->next = head;

		ListNode *slow = dummy;
		ListNode *fast = dummy;

		for(int i=1;i<=n;i++){
			fast = fast->next;
		}        

		while(fast!=NULL and fast->next != NULL){
			fast = fast->next;
			slow = slow->next;
		}

		slow->next = slow->next->next;

		return dummy->next;    
    }
};