class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
                string s=words[i];
                if(pref.size()>s.size()) continue;
                int k=0;
                int j=0;
                while(k!=pref.size() and pref[k]==s[j])
                {
                    k++;
                    cout<<k<<" ";
                    j++;
                }
                if(k==pref.size())
                {
                    cnt++;
                }

        }
        return cnt;
    }
};