
 class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode * dummy=new ListNode();
        dummy->next=head;



        //  **** here u need to initialize fast and slow with dummy and not head
        ListNode * slow=dummy;
       
        ListNode * fast=dummy;
        

        for(int i=1;i<=n;i++){
            fast=fast->next;
        }

        // ** u need to move only until fast->next!=NULL
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        slow->next=slow->next->next;

        // we need to return dummy-next for safer side, because start->next , we can't return , because start may moved
        // it means l==n
        // if(slow== head) return dummy->next->next;
        // return head;

        return dummy->next;
        
    }
};
