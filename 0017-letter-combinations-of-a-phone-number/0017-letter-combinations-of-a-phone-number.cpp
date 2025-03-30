class Solution {
public:
    void  solve(string &digits,vector<string>&ans,string &v,string mapping[],int ind)
    {
        if(ind>=digits.size())
        {
            ans.push_back(v);
            return ;
        }
        int number=digits[ind]-'0';
        string value=mapping[number];
        for(int i=0;i<value.size();i++)
        {
           v.push_back(value[i]);
            solve(digits,ans,v,mapping,ind+1);
            v.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
      vector<string>ans;
      string v="";
      if(digits.size()==0) return {};
      string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      solve(digits,ans,v,mapping,0);
      return ans;
    }
};