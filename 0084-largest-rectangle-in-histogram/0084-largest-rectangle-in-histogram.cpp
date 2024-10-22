class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>leftsmaller;
        stack<int>st;
        st.push(0);
        leftsmaller.push_back(0);
        int n=heights.size();
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                leftsmaller.push_back(0);
            }
            else
            {
                leftsmaller.push_back(st.top()+1);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        vector<int>rightsmaller;
        st.push(n-1);
        rightsmaller.push_back(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                rightsmaller.push_back(n-1);
            }
            else
            {
                rightsmaller.push_back(st.top()-1);
            }
            st.push(i);
        }
        reverse(rightsmaller.begin(),rightsmaller.end());
        int maxarea=0;
        for(int i=0;i<n;i++)
        {
            maxarea=max(maxarea,heights[i]*(rightsmaller[i]-leftsmaller[i]+1));
        }
        return maxarea;
    }
};