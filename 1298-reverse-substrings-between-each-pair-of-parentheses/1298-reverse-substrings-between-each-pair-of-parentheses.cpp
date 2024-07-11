class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if(st.empty()) st.push(s[i]);

           else  if (s[i] == ')') {
                vector<char> ans;
                while (!st.empty()) {
                    if (st.top() != '(') {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    else break;
                }
                st.pop();
                for (int i = 0; i < ans.size(); i++) {
                    st.push(ans[i]);
                }
                ans.clear();
            } 
            else  st.push(s[i]);
        }
        string v = "";
        while (!st.empty()) {
            v += st.top();
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
