class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n=order.size();
        set<int>st={-1,n};
        long long cnt=0;
        for(int i=0;i<n;i++)
        {
            int pos=order[i];
            auto it=st.lower_bound(pos);
            it--;
            long long before=pos-int(*it);
            it=st.upper_bound(pos);
            long long after=int(*it)-pos;
            cnt+=before* after;
            if(cnt>=k) return i;
            st.insert(pos);
        }
        return -1;
    }
};