class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string s="";
        for(int i=0;i<n;i++)
        {
            s+="0";
        }
        unordered_set<string>a(nums.begin(),nums.end());
        if(a.find(s)==a.end()) return s;
        for(int i=0;i<n;i++)
        {
            string b=s;
            b[i]='1';
            if(a.find(b)==a.end()) return b;
        }
        return "";
        

        return "0";
    }
};