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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* curr=head;
        int len=0;
        while(curr->next!=NULL)
        {
            len++;
            curr=curr->next;
        }
        len+=1;
        if(k%len ==0) return head; 
        int x=len-(k%len);
        curr->next=head;
        curr=curr->next;
        int cnt=0;
        while(curr!=nullptr)
        {
           cnt++;
           if(cnt==x)
           {
            head=curr->next;
            curr->next=nullptr;
           }
           curr=curr->next;
        }
        return head;

    }
};