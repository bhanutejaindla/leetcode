class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
              st.push(nums2[i]);
              mp[nums2[i]]=-1;
              continue;
            }
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                mp[nums2[i]]=-1;
            }
            if(!st.empty())
            {
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
            st.push(nums2[i]);
        }
       vector<int>v;
       for(int i=0;i<nums1.size();i++)
       {
         v.push_back(mp[nums1[i]]);
       }
       return v;
    }
};