class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums2.size();
        stack<pair<int,int>>st;
        st.push({nums2[n-1],-1});
        mp[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums2[i]<st.top().first)
            {
                mp[nums2[i]]=st.top().first;
                st.push({nums2[i],st.top().first});
            }
            else
            {
                while(!st.empty() && nums2[i]>=st.top().first)
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    mp[nums2[i]]=st.top().first;
                    st.push({nums2[i],st.top().first});
                    
                }
                else
                {
                    st.push({nums2[i],-1});
                    mp[nums2[i]]=-1;
                }
            }
        }
       vector<int>ans;
       for(int i=0;i<nums1.size();i++)
       {
        ans.push_back(mp[nums1[i]]);
       }
        return ans;
    }
};