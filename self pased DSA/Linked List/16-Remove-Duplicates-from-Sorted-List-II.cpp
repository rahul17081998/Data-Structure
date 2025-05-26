/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.
*/

class Solution {
public:
    // TC = O(NlogN)
    // SC = O(N)
    ListNode* deleteDuplicates(ListNode* head) {
        // create an set and store all the elements into it
        map<int, int> mp;
        ListNode* curr = head;
        while(curr!=NULL){
            mp[curr->val]++;
            curr = curr->next;
        }

        // create a dummy node
        ListNode *dummy = new ListNode(-1);
        ListNode *start=dummy;

        // take each and every elements from the set and and create a node and add it new linklist
        for(auto x: mp){
            if(x.second>1) continue;
            ListNode *temp = new ListNode(x.first);
            start->next = temp;
            start=temp;
        }
      
        return dummy->next;
    }
};
