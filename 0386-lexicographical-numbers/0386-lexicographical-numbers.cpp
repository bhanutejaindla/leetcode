class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string>s;
        for(int i=1;i<=n;i++)
        {
            string v=to_string(i);
            s.push_back(v);
        }
        sort(s.begin(),s.end());
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            ans.push_back(stoi(s[i]));
        }
        return ans;
        
    }
};