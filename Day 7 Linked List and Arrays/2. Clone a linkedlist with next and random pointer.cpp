// 2. Clone a linkedlist with next and random pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// brute - force solution
class Solution {
public:
	Node* copyFunc(node* head, unordered_map<Node*, Node*> &mp){
		if(head == NULL) return NULL;

		Node* newNode = new Node(head->val);
		mp[head] = newNode;

		newNode->next = copyFunc(head->next, mp);

		if(head->random){
			newNode->random = mp[head->random];
		}

		return newNode;
	}

    Node* copyRandomList(Node* head) {
    	unordered_map<Node*, Node*> mp;
    	return copyFunc(head, mp);
    }
};


// optimized with O(1) space
class Solution {
public: 
    Node* copyRandomList(Node* head) {
    	Node* iter = head;
    	Node* front = head;

    	// Step 1: Make copy of each node
    	// and link them together side-by-side in a single list

    	while(iter!=NULL){
    		front = iter->next;

    		Node *copy = new Node(iter->val);
    		iter->next = copy;
    		copy->next = front;

    		iter = front;
    	}


    	// Step 2: assign random pointers to copy nodes
    	iter = head;

    	while(iter!=NULL){
    		if(iter->random!=NULL){
    			iter->next->random = iter->random->next;
    		}

    		iter = iter->next->next;
    	}

    	// step 3: restore the original list, and extract the copy list
    	iter = head;

    	Node* pseudohead = new Node(0);
    	Node* copy = pseudohead;

    	while(iter!=NULL){
    		front = iter->next->next;

    		// extract the copy
    		copy->next = iter->next;

    		// restore the original
    		iter->next = front;

    		copy=copy->next;

    		iter = front;
    	}

    	return pseudohead->next;

    }
};