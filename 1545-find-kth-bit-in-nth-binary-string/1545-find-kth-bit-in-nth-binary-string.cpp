class Solution {
public:
    string helper(string &s)
    {
        int m = s.size();
        string rev = s;
        reverse(rev.begin(),rev.end());
        for (char &c : rev)
        c = (c == '0') ? '1' : '0';
        string newstr = s + "1" + rev;
        return newstr;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=1;i<n;i++)
        {
             s = helper(s);
        }
        cout<<s<<endl;
        return s[k-1];
    }
};