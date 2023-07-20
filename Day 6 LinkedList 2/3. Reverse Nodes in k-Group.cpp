// 3. Reverse Nodes in k-Group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or k==1) return head;

        // creating a dummy node 
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // declaring 3 different nodes that we need 
        ListNode *cur = dummy, *nex = dummy, *pre = dummy;
        int count = 0;

        // count the number of nodes 

        while(cur->next != NULL) {
        	cur = cur->next;
        	count++;
        }

        while(count>=k){
        	cur = pre->next;
        	nex = cur->next;

        	for(int i=1; i<k;i++){
        		cur->next = nex->next;
        		nex->next = pre->next;
        		pre->next = nex;
        		nex = cur->next;
        	}

        	pre = cur;
        	count-=k;
        }

        return dummy->next;
    }
};