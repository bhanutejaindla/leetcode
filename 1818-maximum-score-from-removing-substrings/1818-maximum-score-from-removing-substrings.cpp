class Solution {
public:
     
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        stack<char>st;
        bool flag=false;
        if(x>y) flag=true;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(flag==true && st.top()=='a' && s[i]=='b')
            {
               
                    ans+=x;
                    st.pop();
                  
                
            }
            else if(flag==false && st.top()=='b' && s[i]=='a')
            {   
                ans+=y;
                st.pop();
                
                
            }
           else  st.push(s[i]);
        }
        string v="";
        while(!st.empty())
        {
            v+=st.top();
            cout<<st.top()<<" ";
            st.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(st.empty())
            {
                st.push(v[i]);
            }
            else if(st.top()=='a' && v[i]=='b')
            {
               
                    ans+=x;
                    st.pop();       
            }
            else if(st.top()=='b' && v[i]=='a')
            {   
                ans+=y;
                st.pop();     
            }
           else  st.push(v[i]);
        }
        return ans;
    }
};