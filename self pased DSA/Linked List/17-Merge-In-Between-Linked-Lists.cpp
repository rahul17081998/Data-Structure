


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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr=list1, *tail=list2;
        if(curr==NULL) return NULL;
        ListNode *a_bar=NULL, *b_bar=NULL; 
        int count=0;
        while(curr!=NULL){
            if(count==a-1)
                a_bar = curr;

            if(count==b)
                b_bar = curr->next;

            curr = curr->next;
            count++;
        }

        while(tail->next!=NULL){
            tail=tail->next;
        }

        a_bar->next=list2;
        tail->next=b_bar;
        return list1;

    }
};