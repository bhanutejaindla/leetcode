class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        st.push(nums2[n-1]);
        vector<int>ans;
        ans.push_back(-1);
        unordered_map<int,int>mp;
        mp[nums2[n-1]]=-1;
   
        for(int i=n-2;i>=0;i--)
        {
           while(!st.empty() && nums2[i]>=st.top())
           {
            st.pop();
           }
           if(!st.empty())
           {
            mp[nums2[i]]=st.top();
            ans.push_back(st.top());
           }
           else
           {
            mp[nums2[i]]=-1;
            ans.push_back(-1);
           }
           st.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        vector<int>v;
        for(int i=0;i<nums1.size();i++)
        {
          v.push_back(mp[nums1[i]]);
        }
        return v;
    }
};