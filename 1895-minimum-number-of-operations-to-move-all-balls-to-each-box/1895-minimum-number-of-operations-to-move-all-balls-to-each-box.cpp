class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<boxes.size();i++)
        {
            char ch=boxes[i];
            mp[ch].push_back(i);
        }
        // vector<int>ans;
        for(int i=0;i<boxes.size();i++)
        {
            int sum=0;
            for(auto x:mp['1'])
            {
                sum+=abs(x-i);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};