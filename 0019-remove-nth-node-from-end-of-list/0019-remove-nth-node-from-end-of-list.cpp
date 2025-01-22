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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* dummy=head;
        ListNode* ans=head;
        while(dummy!=nullptr)
        {
            len++;
            dummy=dummy->next;
        }
        if(len==n) return head->next;
        int x=len-n;
        int cnt=0;
        while(head!=nullptr)
        {
            cnt++;
            if(cnt==x)
            {
                ListNode* Next=head->next->next;
                head->next=nullptr;
                head->next=Next;
                break;
            }
            head=head->next;
        }
        return ans;

    }
};