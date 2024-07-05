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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* l1=new ListNode(-1);
        ListNode* l2=head->next;
        l1->next=head;
        int count=0;
        vector<int>ans;
        if(head->next->next==NULL)  return {-1,-1};
        head=head->next;
        l2=l2->next;
        l1=l1->next;
        int i=1;
        while(l2!=NULL && head->next!=NULL)
        {
              i++;
              if(head->val>l1->val && head->val>l2->val)
              {
                  ans.push_back(i);
              }
              else if(head->val<l1->val && head->val<l2->val)
              {
                  ans.push_back(i);
              }
              else count++;
              head=head->next;
              l2=l2->next;
              l1=l1->next;
        }
        sort(ans.begin(),ans.end());
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
        int n=ans.size();
        if(n>1){
        int a=INT_MAX;
        for(int i=1;i<n;i++)
        {
            a=min(a,ans[i]-ans[i-1]);
        }
        int b=ans[n-1]-ans[0];
        return {a,b};
        }
     return {-1,-1}; 
        
    }
};