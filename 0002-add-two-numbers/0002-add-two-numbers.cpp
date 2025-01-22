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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;
        int carry=0,a=0,b=0;
        while(l1!=NULL || l2!=NULL)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
            }
             if(l2!=NULL)
             {
                sum+=l2->val;
             }
             sum+=carry;
            if(sum>=10)
            {
                dummy->next=new ListNode(sum%10);
                carry=sum/10;
            }
            else
            {
                dummy->next=new ListNode(sum);
                carry=0;
            }
            dummy=dummy->next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        if(carry!=0) dummy->next=new ListNode(carry);
        return ans->next;
    }
};