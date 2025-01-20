class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(i);
                prev[i]=0;
                continue;
            }
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                prev[i]=0;
            }
            if(!st.empty())
            {
                prev[i]=st.top()+1;
            }
            st.push(i);
        }
        for(auto it:prev)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        while(!st.empty()) st.pop();
        vector<int>next(n,n-1);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(i);
                next[i]=n-1;
                continue;
            }
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                next[i]=n-1;
            }
            if(!st.empty())
            {
                next[i]=st.top()-1;
            }
            st.push(i);
        }
         for(auto it:next)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        int maxiarea=0;
        for(int i=0;i<n;i++)
        {
            maxiarea=max(maxiarea,(next[i]-prev[i]+1)*heights[i]);
        }
        return maxiarea;
    }
};