class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n=s.size();
        string res="";
        int freq=0;
        int pointer=0;
        sort(s.rbegin(),s.rend());
        for(int i=0;i<n;i++)
        {
            if(!res.empty() && res.back()==s[i])
            {
                if(freq<repeatLimit)
                {
                    res+=s[i];
                    freq++;
                }
                else
                {
                    pointer=max(pointer,i+1);
                    while(pointer<s.size() && s[pointer]==s[i])
                    {
                        pointer++;
                    }
                    if(pointer<s.size())
                    {
                        res+=s[pointer];
                        swap(s[pointer],s[i]);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                res+=s[i];
                freq=1;
            }
        }
        return res;
    }
};