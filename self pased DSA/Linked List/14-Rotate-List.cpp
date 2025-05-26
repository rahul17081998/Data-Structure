
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *slow = head, *curr=head, *tail=head;
        if(head==NULL) return head;

        int n=0; // count number of nodes
        while(curr!=NULL){
            curr=curr->next;
            n++;
        }
        
        // k can be grater than node value so
        int x = k%n;
        if(k==0) return head; // without modyfying
        // find tail of the link list
        while(tail->next!=NULL){
            tail=tail->next;
        }
        // go to 
        cout<<n<<" "<<x<<" "<<k<<endl;
        int count=1;
        curr = head;
        while(curr!=NULL && count<n-x){
            curr=curr->next;
            count++;
        }

        tail->next=head; // make cycle
        head = curr->next; // mark new head
        curr->next = NULL; // cut the cycle
        return head;
    }
};