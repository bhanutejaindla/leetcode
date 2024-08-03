class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       unordered_map<int,int>mp,mp1;
       for(int i=0;i<target.size();i++)
       {
        mp[target[i]]++;
        mp1[arr[i]]++;
       }
       return mp==mp1;
    }
};