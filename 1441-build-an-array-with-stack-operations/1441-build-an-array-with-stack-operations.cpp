class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        set<int>s(target.begin(),target.end());
        for(auto x: s)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        vector<string>ans;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end())
            {
                cout<<"Yes"<<endl;
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(s.find(i)!=s.end())
            {
                v.push_back(i);
                ans.push_back("Push");
            }
            if(v == target) break;
         }
        return ans;
    }
};