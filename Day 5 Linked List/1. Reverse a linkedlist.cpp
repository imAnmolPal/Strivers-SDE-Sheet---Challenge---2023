// 1. Reverse a linkedlist

// basically we have to reverse the arrows 

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode *dummy = NULL;
    while(head!=NULL){
    	// taking hold of rest of the list
    	LinkedListNode *next = head->next;

    	// making current node point to prev node
    	head->next = dummy;

    	// making current node as dummy.
    	dummy = head;

    	// making next node has head, so that we repeat the process
    	head = next;
    }

    return dummy;
}