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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;
        int count=0;
        ListNode* ans=new ListNode(-1);
        ListNode* v=ans;
        int sum=0;
        while(head!=NULL)
        {
            if(head->val==0) count++;
            sum+=head->val;
            if(count==2 )
            {
                  ans->next=new ListNode(sum);
                  count=1;
                  ans=ans->next;
                  sum=0;
            }
            head=head->next;
        }
        return v->next;
    }
};