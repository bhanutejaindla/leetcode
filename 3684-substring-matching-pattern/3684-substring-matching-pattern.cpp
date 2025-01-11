class Solution {
public:
    bool hasMatch(string s, string p) {
        int x=p.find("*");
        string b=p.substr(0,x);
        string c=p.substr(x+1);
        int ind1=s.find(b);
        int ind2=s.rfind(c);
        return ind1!=-1 && ind2!=-1 && ind1+b.size()<=ind2;
        
    }
};