// 3. Merge two sorted list

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val > list2->val){
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
        }

        ListNode* res = list1;

        while(list1!=NULL and list2!=NULL){
            ListNode *temp = NULL;
            while(list1!=NULL and list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }

            temp->next = list2;
            ListNode* tmp = list1;
            list1 = list2;
            list2 = tmp;
        }

        return res;
    }
};