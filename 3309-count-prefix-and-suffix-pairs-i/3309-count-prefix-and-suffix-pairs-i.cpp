class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            string t=words[i];
            for(int j=i+1;j<n;j++)
            {
                string s=words[j];
                 if(i!=j && s.size()>=t.size())
                 {
                    cout<<s<<" "<<t<<endl;
                    int k=0;
                    while(k<t.size() )
                    {
                        if(t[k]==s[k])
                        {
                            k++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(k==t.size())
                    {
                        k=s.size()-1;
                        int l=t.size()-1;
                        while(l>=0)
                        {
                            if(s[k]==t[l])
                            {
                                k--;
                                l--;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(l<0) count++;
                    }
                 }
            }
        }
        return count;
    }
};