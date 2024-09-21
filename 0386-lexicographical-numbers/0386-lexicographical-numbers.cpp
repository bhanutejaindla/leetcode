class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            string a=to_string(i);
            ans.push_back(a);
        }
        sort(ans.begin(),ans.end());
        vector<int>v;
        for(int i=0;i<ans.size();i++)
        {
            v.push_back(stoi(ans[i]));
        }
        return v;
        
    }
};