// 2. Detect a Cycle in Linked List

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
    bool hasCycle(ListNode *head) {
	        if(head == NULL or head->next==NULL) return false;
			
			// take two dummy nodes 
			ListNode *fast = head;
			ListNode *slow = head;

			// iterate over the linkedlist
			while(fast->next and fast->next->next){
				fast = fast->next->next;
				slow = slow->next;

				// check if the node is same
				if(fast == slow) return true;
			}        

			return false;
    }
};