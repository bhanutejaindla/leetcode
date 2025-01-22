/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>s;
        while(headA!=NULL)
        {
            ListNode* a=headA;
            s.insert(a);
            headA=headA->next;
        }
        while(headB!=NULL)
        {
            ListNode* a=headB;
            if(s.find(a)!=s.end()) return a;
            headB=headB->next;
        }
        return nullptr;
    }
};