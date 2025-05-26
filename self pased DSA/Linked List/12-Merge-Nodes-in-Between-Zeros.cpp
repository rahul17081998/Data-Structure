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


/*
Problem statement:
You are given the head of a linked list, which contains a series of integers 
separated by 0's. The beginning and end of the linked list will have 
Node.val == 0.
For every two consecutive 0's, merge all the nodes lying in between them into a 
single node whose value is the sum of all the merged nodes. The modified list 
should not contain any 0's. Return the head of the modified linked list.


Approach:
sum all the value between two zeros and make a tempery new node of value = sum 
and add them with dummy linklist and at last return dummy->next
*/
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* curr = head->next;
        ListNode* dummy = new ListNode(-1); // crate a new dummy node
        ListNode* prev = dummy;
        
        while(curr!=NULL)
        {
            int sum = 0;
            while(curr->val!=0)
            {
                sum = sum + curr->val;
                curr = curr->next;
            }
            // create a new node
            ListNode* temp = new ListNode(sum);
            prev ->next = temp;
            prev = prev -> next;
            // increase current pointer, bcz it have 0 value
            curr = curr ->next;
        }
        return dummy -> next;
    }
};