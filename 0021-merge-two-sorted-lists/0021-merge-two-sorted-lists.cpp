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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2)  return list1;
        ListNode* head=new ListNode(-1);
        ListNode* ans=head;
        while(list1!=NULL || list2!=NULL)
        {
            if(list1 && list2){
            if(list1->val<=list2->val)
            {
                head->next=new ListNode(list1->val);
                list1=list1->next;
            }
            else if(list1->val>list2->val)
            {
                head->next=new ListNode(list2->val);
                list2=list2->next;
            }
            }
            else if(!list1)
            {
                head->next=new ListNode(list2->val);
                list2=list2->next;
            }
           else if(!list2)
            {
                head->next=new ListNode(list1->val);
                list1=list1->next;
            }
            head=head->next;
        }
        // while(list1!=NULL)
        // {
        //      head->next=new ListNode(list1->val);
        //      list1=list1->next;
        //      head=head->next;
        // }
        // while(list2!=NULL)
        // {
        //      head->next=new ListNode(list2->val);
        //      list2=list2->next;
        //      head=head->next;
        // }
        return  ans->next;
    }
};