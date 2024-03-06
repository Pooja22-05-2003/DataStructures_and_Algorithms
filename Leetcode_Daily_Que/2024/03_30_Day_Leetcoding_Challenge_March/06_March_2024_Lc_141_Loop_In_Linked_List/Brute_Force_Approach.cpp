// Tortoise and Hair Algorithm 
// Slow and Fast Pointer concept


// TC=O(N)
// SC=O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode * slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {

            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
          
        }

        return false;
    }
};