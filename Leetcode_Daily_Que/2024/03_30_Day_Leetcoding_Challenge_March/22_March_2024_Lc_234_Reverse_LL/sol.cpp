
class Solution {
public:
    ListNode* ReverseLL(ListNode*head)
    {
        ListNode * prev=NULL;
        ListNode* curr=head;

        while(curr)
        {
            // store the next pointer before breaking the connection
            ListNode * next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        return prev;
    }

    ListNode* FindMidLL(ListNode*head)
    {
        // tortoise algo
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid=FindMidLL(head);
     
        ListNode* head1=ReverseLL(mid->next);

        // check whether the first half and the second reversed half is equal or not
        while(head1 )
        {
            if(head->val!=head1->val) return false;
            head=head->next;
            head1=head1->next;
        }

        return true;
    }
};