class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt=0;
        if(list1==NULL) return NULL;
        ListNode*last1List1=list1;
        ListNode*last2List1=NULL;
        ListNode*last1List2=list2;
        ListNode*last2List2=NULL;
        while(last1List1!=NULL && cnt!=(a-1))
        {
            last1List1=last1List1->next;
            cnt++;
        }

        last2List1=last1List1;
        if(last2List1!=NULL )
        {
            while(last2List1!=NULL && cnt!=(b+1))
            {
                last2List1=last2List1->next;
                cnt++;
            }
        }

        last2List2=list2;
        while(last2List2->next!=NULL)
        {
            last2List2=last2List2->next;
        }
        cout<<last1List1->val<<","<<last2List1->val<<","<<last1List2->val<<","<<last2List2->val<<endl;
        
        
        last1List1->next=NULL;
        if(last1List1)
        {
        last1List1->next=last1List2;
        last2List2->next=last2List1;
        }

        return list1;
    }
};