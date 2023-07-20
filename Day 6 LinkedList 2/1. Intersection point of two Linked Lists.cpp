// 1. Intersection point of two Linked Lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL or headB == NULL) return NULL;

        ListNode *a = headA;
        ListNode *b = headB;

        // if a and b have diff len, then we willstop the loop after second iteration
        while(a!=b){
            // for the end of first iteration, we just reset the point to the head of another linked list
            a = a==NULL? headB : a->next;
            b = b==NULL? headA : b->next;
        }

        return a;
    }
};