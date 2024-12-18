class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>res=prices;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && res[st.top()]>=prices[i])
            {
                res[st.top()]-=prices[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};