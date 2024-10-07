class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        int k=n;
        while(k--)
        {
            for(int i=1;i<n;i++)
            {
                if((s[i]=='B' &&s[i-1]=='A') || (s[i]=='D' && s[i-1]=='C'))
                {
                    s.erase(s.begin()+i);
                    s.push_back('1');
                    s.erase(s.begin()+i-1);
                    s.push_back('1');
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='1')  cnt++;
        }
        return cnt;
    }
};