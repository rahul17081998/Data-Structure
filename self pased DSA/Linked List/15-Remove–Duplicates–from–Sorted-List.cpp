/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.
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

// TC : O(N)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head, *curr=head->next;

        while(curr!=NULL){

            while(curr!=NULL && slow->val==curr->val){
                curr = curr->next;
            }
            slow->next=curr;
            slow = curr;
            if(curr!=NULL)
                curr = curr->next;
        }
        return head;
    }
};

                                                 