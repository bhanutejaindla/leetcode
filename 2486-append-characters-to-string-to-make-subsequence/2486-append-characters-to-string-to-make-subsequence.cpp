class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size();
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[j])
            {
                j++;
            }
        }
        if(j==t.size()) return 0;
        else return (t.size()-j);
    }
};